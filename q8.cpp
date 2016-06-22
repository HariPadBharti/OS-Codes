/*
 *  Solution to Producer Consumer Problem
 *  Using Ptheads, a mutex and condition variables
 *  From Tanenbaum, Modern Operating Systems, 3rd Ed.
 */

/*
    In this version the buffer is a single number.
    The producer is putting numbers into the shared buffer
    (in this case sequentially)
    And the consumer is taking them out.
    If the buffer contains zero, that indicates that the buffer is empty.
    Any other value is valid.
*/

#include <cstdio>
#include <pthread.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX 10			/* Numbers to produce */
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;
char buffer[20],s[]="hello world";
int i=0;
 int j=0;

void* producer(void *ptr) {
  

  for (i; i <strlen(s); i++) {
    pthread_mutex_lock(&the_mutex);	/* protect buffer */
    //while (buffer != 0)		       
      //pthread_cond_wait(&condp, &the_mutex);
    buffer[i] = s[i];
    cout<<"buffer in producer = "<<buffer[i]<<endl;
    
    pthread_cond_signal(&condc);	/* wake up consumer */
    pthread_mutex_unlock(&the_mutex);	/* release the buffer */
    
  }
  pthread_exit(0);
}

void* consumer(void *ptr) {
 

  for (j; j <strlen(s); j++) {
    pthread_mutex_lock(&the_mutex);	/* protect buffer */
    if(j>=i)			
{
cout<<"still waiting\n";
      pthread_cond_wait(&condc, &the_mutex);
}
 
 
    cout<<"buffer in consumer = "<<buffer[j]<<endl;
    pthread_mutex_unlock(&the_mutex);	/* release the buffer */
    pthread_cond_signal(&condp);	/* wake up consumer */
    
  }
  pthread_exit(0);
}

int main(int argc, char **argv) {
  pthread_t pro, con;

  // Initialize the mutex and condition variables
  /* What's the NULL for ??? */
  pthread_mutex_init(&the_mutex,0);	
  pthread_cond_init(&condc, 0);		/* Initialize consumer condition variable */
  pthread_cond_init(&condp, 0);		/* Initialize producer condition variable */

  // Create the threads
  
  pthread_create(&pro, NULL, producer, NULL);
  pthread_create(&con, NULL, consumer, NULL);
  pthread_join(pro, NULL);
  pthread_join(con, NULL);
  fflush(stdout);

  // Cleanup -- would happen automatically at end of program
  pthread_mutex_destroy(&the_mutex);	/* Free up the_mutex */
  pthread_cond_destroy(&condc);		/* Free up consumer condition variable */
  pthread_cond_destroy(&condp);		/* Free up producer condition variable */

}

