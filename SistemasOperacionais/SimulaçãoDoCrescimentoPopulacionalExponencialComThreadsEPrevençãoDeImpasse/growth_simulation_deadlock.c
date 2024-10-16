#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <unistd.h>

#define NULL ((void *)0)
#define THREAD_WORK_TIME 100000

//* mutex array
pthread_mutex_t* space;
pthread_mutex_t* resource;
int space_array_size=0;
int resorce_array_size=0;
//* wait list
int* waiting_for_space;
int* waiting_for_resource;
pthread_mutex_t m_waiting_for_space;
pthread_mutex_t m_waiting_for_resource;
//* control main
int threads2run=0;
pthread_mutex_t lockthreads2run;
pthread_mutex_t stay_on;

typedef struct Colony
{
    int id, p0, t, tn, m_space_index, m_resource_index;
    double population, r;
}COLONY;

//* sub threads number to run
void subThreads2Run();
//* Space provider
int lockSpaceProvider(COLONY* cln);
void unlockSpaceProvider(COLONY* cln);
//* Resource provider
int lockResourceProvider(COLONY* cln);
void unlockResourceProvider(COLONY* cln);
//* bacterial colony
COLONY* createColony(int id, int p0, int t, double population, double r);
//* thread
void* bacterialColony(void* colony);

//* main
int main()
{
  //* initial pop
  int p0=2;
  //* times
  int t=10;
  //* grow rate
  double r=1.2;
  //* how many threads
  int colony_number = 15;

  //* how many resorces
  space_array_size = 3;
  resorce_array_size = 5;

  //* mutex alloc
  space=(pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)*space_array_size);
  resource=(pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)*resorce_array_size);

  //* wait list alloc
  waiting_for_space=(int*)malloc(sizeof(int)*space_array_size);
  waiting_for_resource=(int*)malloc(sizeof(int)*resorce_array_size);

  //*mutex init
  for (size_t i = 0; i < space_array_size; i++)
  {
    if (pthread_mutex_init(&(space[i]), NULL) != 0)
    {
      printf("\n mutex init has failed\n");
      return 1;
    }
  }
  for (size_t i = 0; i < resorce_array_size; i++)
  {
    if (pthread_mutex_init(&(resource[i]), NULL) != 0)
    {
      printf("\n mutex init has failed\n");
      return 1;
    }
  }

  printf("Starting with %i colonies \n", colony_number);

  //* thread array
  pthread_t thread_point[colony_number];
  //* run threads
  threads2run = colony_number;
  pthread_mutex_lock(&stay_on);

  COLONY** cln_array = (COLONY**) malloc(sizeof(COLONY**));
  for (size_t i = 0; i < colony_number; i++)
  {
    cln_array[i] = createColony(i, p0, t, p0, r);
  }
  for (int x = 0; x < colony_number; x++)
  {
    pthread_create(&thread_point[x], NULL, &bacterialColony, cln_array[x]);
    pthread_detach(thread_point[x]);
  }
  //*wait end
  pthread_mutex_lock(&stay_on);

  //*free
  for (size_t i = 0; i < colony_number; i++)
  {
    free(cln_array[i]);
  }
  free(cln_array);
  free(waiting_for_space);
  free(waiting_for_resource);
  free(resource);
  free(space);
  return 0;
}

//* sub threads number to run
void subThreads2Run()
{
  //wait to use
  pthread_mutex_lock(&lockthreads2run);
  threads2run--;
  if (threads2run == 0)
  {
    pthread_mutex_unlock(&stay_on);
  }
  pthread_mutex_unlock(&lockthreads2run);
}

//* Space provider
int lockSpaceProvider(COLONY* cln)
{
  //* try to find one free
  for (size_t i = 0; i < space_array_size; i++)
  {
    //* verify if is free
    if (pthread_mutex_trylock(&space[i])==0)
    {
      //! already lock
      // pthread_mutex_lock(&(space[i]));
      //* save to unlock late
      cln->m_space_index = i;
      return 1;
    }
  }

  //* find the small and wait
  int small_index = 0;
  for (size_t i = 0; i < space_array_size; i++)
  {
    if (waiting_for_space[small_index] > waiting_for_space[i])
    {
      small_index=i;
    }
  }
  //*list
  pthread_mutex_lock(&m_waiting_for_space);
  waiting_for_space[small_index]+=1;
  pthread_mutex_unlock(&m_waiting_for_space);

  //*lock
  pthread_mutex_lock(&space[small_index]);

  //*list
  pthread_mutex_lock(&m_waiting_for_space);
  waiting_for_space[small_index]-=1;
  pthread_mutex_unlock(&m_waiting_for_space);

  //* save to unlock late
  cln->m_space_index = small_index;
  return 2;
}
void unlockSpaceProvider(COLONY* cln)
{
  pthread_mutex_unlock(&space[cln->m_space_index]);
  cln->m_space_index=-1;
}

//* Resource provider
int lockResourceProvider(COLONY* cln)
{
  //* try to find one free
  for (size_t i = 0; i < resorce_array_size; i++)
  {
    //* verify if is free
    if (pthread_mutex_trylock(&resource[i])==0)
    {
      //! already lock
      // pthread_mutex_lock(&resource[i]);
      //* save to unlock late
      cln->m_resource_index = i;
      return 1;
    }
  }

  //* find the small and wait
  int small_index = 0;
  for (size_t i = 0; i < resorce_array_size; i++)
  {
    if (waiting_for_resource[small_index] > waiting_for_resource[i])
    {
      small_index=i;
    }
  }
  //*list
  pthread_mutex_lock(&m_waiting_for_resource);
  waiting_for_resource[small_index]+=1;
  pthread_mutex_unlock(&m_waiting_for_resource);

  //* wait
  pthread_mutex_lock(&resource[small_index]);

  //*list
  pthread_mutex_lock(&m_waiting_for_resource);
  waiting_for_resource[small_index]-=1;
  pthread_mutex_unlock(&m_waiting_for_resource);

  //* save to unlock late
  cln->m_resource_index = small_index;
  return 2;
}
void unlockResourceProvider(COLONY* cln)
{
  pthread_mutex_unlock(&resource[cln->m_resource_index]);
  cln->m_resource_index=-1;
}

//* bacterial colony
COLONY* createColony(int id, int p0, int t, double population, double r)
{
  COLONY* cln = (COLONY*) malloc(sizeof(COLONY));
  if (cln != NULL)
  {
    cln->id = id;
    cln->p0 = p0;
    cln->t = t;
    cln->tn = 0;
    cln->m_resource_index = -1;
    cln->m_space_index = -1;
    cln->population = population;
    cln->r = r;
      return cln;
  }else
  {
    return NULL;
  }
}
//* thread
void* bacterialColony(void* colony)
{
  // fix pointer
  COLONY* cln = colony;

  //*code
  printf("thread %i start \n", cln->id);

  //*threads
  for (cln->tn; cln->tn < cln->t; cln->tn++)
  {
    //* force deadlock
    // this or a semaphore
    if ((rand()%2) == 1)
    {
      //*lock
      lockSpaceProvider(cln);
      lockResourceProvider(cln);
    }else
    {
      //*lock
      lockResourceProvider(cln);
      lockSpaceProvider(cln);
    }

    //* do samething with the resorces
    // sleep is importante to force a deadlock
    usleep(THREAD_WORK_TIME);

    //*calc
    cln->population = cln->p0 * exp((cln->r*cln->tn));

    printf("thread %03i grow, time=%03i, resorces: s%03i, r%03i ,now pop=%.2lf \n", cln->id, ((int)cln->tn), cln->m_space_index, cln->m_resource_index, cln->population);

    //* unlock
    unlockSpaceProvider(cln);
    unlockResourceProvider(cln);

    //* rest
    usleep(THREAD_WORK_TIME/2);
  }

  printf("\033[0;32mthread %03i end with pop=%lf \033[0m\n", cln->id, cln->population);
  //*end
  subThreads2Run();
  // exit the current thread
  pthread_exit(NULL);
}