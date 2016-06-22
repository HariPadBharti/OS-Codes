#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 5
//shared variable counter
int counter=0;

struct buffer
{
int b[N];
int in,out;
}item;

void *P()
{
      int i=1;
      while(1)
	{
	while(counter==N);
	item.b[item.in]=i;
	item.in=(item.in+1)%N;
	counter++;
	printf("\nProduced :%d",i++);
	printf("\n Counter value in Producer: %d",counter);
	
       }
       sleep(1);
}

void *C()
{
int item1;
while(1)
{
while(counter==0);
item1=item.b[sleep(2);item.out];
item.out=(item.out+1)%N;
counter--;
printf("\nConsumed :%d",item1);
printf("\n Counter value in Consumer: %d",counter);

}
sleep(1);
}
void main()
{
item.in=0;
item.out=0;
pthread_t t1,t2;
pthread_create(&t1,NULL,P,NULL);
pthread_create(&t2,NULL,C,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("\n Counter value in Main: %d",counter);
}
