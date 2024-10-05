#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#include <setjmp.h> //try catch

#ifdef __linux__
    #include <unistd.h>
#elif _WIN32
    #include <windows.h>
    #include <conio.h>

    void usleep(int time)
    {
        Sleep(time/1000);
    };
#endif

#define TRY do{ jmp_buf ex_buf__; switch( setjmp(ex_buf__) ){ case 0:
#define CATCH(x) break; case x:
#define ETRY } }while(0)
#define THROW(x) longjmp(ex_buf__, x)
#define TIME_OUT_EXCEPTION (1)


#define NULL ((void *)0)

pthread_mutex_t space;
pthread_mutex_t resource;
int threads2run=0;
pthread_mutex_t lockthreads2run;
pthread_mutex_t stay_on;

typedef struct Colony
{
    int id, p0, t;
    double population, r;
}COLONY;

//* sub threads to run

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
void* lockSpaceProvider()
{
  //wait to use
  return pthread_mutex_lock(&space);
}
void unlockSpaceProvider()
{
  return pthread_mutex_unlock(&space);
}

//* Resource provider
int lockResourceProvider()
{
  //wait to use
  return pthread_mutex_lock(&resource);
}
int unlockResourceProvider()
{
  return pthread_mutex_unlock(&resource);
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
  for (size_t i = 0; i < cln->t; i++)
  {
    //* https://web.archive.org/web/20091104065428/http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html
    // TRY
    // {
    //     printf("In Try Statement\n");
    //     THROW( TIME_OUT_EXCEPTION );
    //     printf("I do not appear\n");
    // }
    // CATCH( TIME_OUT_EXCEPTION )
    // {
    //     printf("thread %i wait too much and lost Resorce or Space\n", cln->id);
    // }
    lockSpaceProvider();
    lockResourceProvider();

    unlockSpaceProvider();
    usleep((rand()%10*100000));

    cln->population = cln->p0 * exp((cln->r*i));

    printf("thread %i grow, time=%i ,now pop=%lf \n", cln->id, ((int)i), cln->population);

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
  int colony_number = 12;

  printf("Starting with %i colonies \n", colony_number);

  //* thread array
  pthread_t thread_point[colony_number];
  //* run threads
  threads2run = colony_number;
  pthread_mutex_lock(&stay_on);
  for (int x = 0; x < colony_number; x++)
  {
    COLONY* cln = createColony(x, p0, t, 2.0, r);
    pthread_create(&thread_point[x], NULL, &bacteriaColony, cln);
    pthread_detach(thread_point[x]);
  }
  //*wait end
  pthread_mutex_lock(&stay_on);

  return 0;
}