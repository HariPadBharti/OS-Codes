/*PRODUCER CONSUMER */
#include<stdio.h>
#include<pthread.h>

#include<stdlib.h>
#define N 5
struct buffer
{
	int b[N];
	int count; int mut;
	int in,out;
}buf;

void* Producer()
{
	int i=1;
	while(1)
	{
		if(buf.count<N&&buf.mut==1)
		{buf.b[buf.in]=i; buf.mut=0;
		buf.in=(buf.in+1)%N;
		buf.count++;
		printf("Produced :%d. Remaining:%d\n",i,buf.count);  i++; buf.mut=1;}

		sleep(1);
		
		
	}
}

void* Consumer()
{
	int item;
	while(1)
	{
		if(buf.count>0 && buf.mut==1){
		buf.count--;
		item=buf.b[buf.out];  buf.mut=0;
		buf.out=(buf.out+1)%N;
		printf("Consumed :%d. Remaining:%d\n",item,buf.count); buf.mut=1;}

		sleep(2);
	
	}
}

void main()
{
	pthread_t t1,t2;
	buf.count=0; buf.mut=1;
	buf.in=0;
	buf.out=0;
	
	pthread_create(&t1,NULL,Producer,NULL);
	pthread_create(&t2,NULL,Consumer,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_exit(NULL);
}

