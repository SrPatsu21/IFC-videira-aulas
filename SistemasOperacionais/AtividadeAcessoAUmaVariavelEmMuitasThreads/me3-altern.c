/*
Acesso concorrente a uma variável por muitas threads, solução com alternância.

Compilar com gcc -Wall me3-altern.c -o me3 -lpthread

*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS  100
#define NUM_STEPS 100000

int sum  = 0 ;
int turn = 0 ;

// enter critical section
void enter_cs (long int id)
{
  while (turn != id) ;   // busy waiting (espera ocupada)

  if (sum % 100 == 0)
    printf ("Turn: %d, Sum: %d\n", turn, sum) ;
}

// leave critical section
void leave_cs ()
{
  turn = (turn + 1) % NUM_THREADS ;
}

void *threadBody(void *id)
{
  int i ;

  for (i=0; i< NUM_STEPS; i++)
  {
    enter_cs ((long int) id) ;
    sum += 1 ;   // critical section
    leave_cs () ;
  }

  pthread_exit (NULL) ;
}

int main (int argc, char *argv[])
{
  pthread_t thread [NUM_THREADS] ;
  pthread_attr_t attr ;
  long i, status ;

  // define attribute for joinable threads
  pthread_attr_init (&attr) ;
  pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_JOINABLE) ;

  // create threads
  for(i=0; i<NUM_THREADS; i++)
  {
    status = pthread_create (&thread[i], &attr, threadBody, (void *) i) ;
    if (status)
    {
      perror ("pthread_create") ;
      exit (1) ;
    }
  }

  // wait all threads to finish
  for (i=0; i<NUM_THREADS; i++)
  {
    status = pthread_join (thread[i], NULL) ;
    if (status)
    {
      perror ("pthread_join") ;
      exit (1) ;
    }
  }

  printf ("Sum should be %d and is %d\n", NUM_THREADS*NUM_STEPS, sum) ;

  pthread_attr_destroy (&attr) ;
  pthread_exit (NULL) ;
}