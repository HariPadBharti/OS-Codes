#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t chopstick[5];

void* p(void* arg)
{
int i=*((int*)(arg));
int j=0;

     while(1){
         printf("philosopher %d is waiting.\n",i);
         if(i%2==0){
         sem_wait(&chopstick[i] );
	 sem_wait(&chopstick[ (i + 1) % 5] );}
         else{ sem_wait(&chopstick[ (i + 1) % 5] );
	  sem_wait(&chopstick[i] );
         }
	
	 printf("philosopher %d is eating.\n",i);
         while(j++<1000);
         printf("philosopher %d has completed eating.\n",i);
         
	  sem_post(&chopstick[i] );
          sem_post(&chopstick[ (i + 1) % 5]);


}

}
    
void main()
{       int arg[5];
	pthread_t t[5];
       
        int j=0;
        for(j=0;j<5;j++)
        {sem_init(&(chopstick[j]),0,1);
         arg[j]=j;
        }
	for(j=0;j<5;j++)
	{
	pthread_create(&t[j],NULL,p,(void *)&arg[j]);
        }
	for(j=0;j<5;j++)
	{pthread_join(t[j],NULL);}

}

