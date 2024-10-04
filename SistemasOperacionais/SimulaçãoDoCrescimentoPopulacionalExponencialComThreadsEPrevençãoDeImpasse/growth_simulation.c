#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define NULL ((void *)0)

pthread_mutex_t space;
pthread_mutex_t resource;
int threads2run=0;
pthread_mutex_t lockthreads2run;

typedef struct Colony
{
    int id, p0, t;
    double population, r;
}COLONY;

//* sub threads to run

void* subThreads2Run()
{
  //wait to use
  pthread_mutex_lock(&lockthreads2run);
  threads2run--;
  pthread_mutex_unlock(&lockthreads2run);
}

//* Space provider
void* lockSpaceProvider()
{
  //wait to use
  pthread_mutex_lock(&space);
}
void unlockSpaceProvider()
{
    pthread_mutex_unlock(&space);
}

//* Resource provider
void* lockResourceProvider()
{
  //wait to use
    pthread_mutex_lock(&resource);
}
void unlockResourceProvider()
{
    pthread_mutex_unlock(&resource);
}

//* bacteria colony
COLONY* createColony(int id, int p0, int t, double population, double r)
{
  COLONY* cln = (COLONY*) malloc(sizeof(COLONY));
  if (cln != NULL)
  {
    cln->id = id;
    cln->p0 = p0;
    cln->t = t;
    cln->population = population;
    cln->r = r;
      return cln;
  }else
  {
    return NULL;
  }
}

void* bacteriaColony(void* colony)
{
  // fix pointer
  COLONY* cln = colony;

  //*code
  printf("thread %i start \n", cln->id);

  //*threads
  // pthread_t thread_space_provider;
  // pthread_t thread_resource_provaider;

  // pthread_create(&thread_space_provider, NULL, &lockSpaceProvider, NULL);
  // pthread_create(&thread_resource_provaider, NULL, &lockResourceProvider, NULL);

  for (size_t i = 0; i < cln->t; i++)
  {
    // pthread_join(thread_space_provider, NULL);
    // pthread_join(thread_resource_provaider, NULL);
    lockSpaceProvider();
    lockResourceProvider();

    usleep((rand()%10*100000));

    cln->population = cln->p0 * exp((cln->r*i));

    printf("thread %i grow, time=%i ,now pop=%lf \n", cln->id, ((int)i), cln->population);

    unlockSpaceProvider();
    unlockResourceProvider();
  }

  printf("thread %i end with pop=%lf \n", cln->id, cln->population);
  //*end
  subThreads2Run();
  // exit the current thread
  pthread_exit(NULL);
}

//** main
int main()
{
  int p0=2, t=10;
  double r=1.2;

  //* how much threads
  int cores= get_nprocs();
  if (cores < 6)
  {
    cores = 6;
  }
  printf("Starting with %i colonies \n", cores);

  //* thread array
  pthread_t thread_point[cores];
  //* run threads
  threads2run = cores;
  for (int x = 0; x < cores; x++)
  {
    COLONY* cln = createColony(x, p0, t, 2.0, r);
    pthread_create(&thread_point[x], NULL, &bacteriaColony, cln);
    pthread_detach(thread_point[x]);
  }
  //*wait end
  while (threads2run)
  {
  }

  return 0;
}