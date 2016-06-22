#include <stdio.h>
#include <semaphore.h>
#define N 5

sem_t chair[N];
int TRUE = 1;
int barber_chair;
int EMPTY = -1;

void customer(int i){
       do  { 
             sem_wait (&chair[i]);
	     sem_wait (&(chair[(i + 1) % N]));

		barber_chair = *((int*)&chair[i]);	
	     printf("%d\n",&barber_chair);
             sem_post(&chair[i]);
	     sem_post(&(chair[(i + 1) % N]));

	     barber_chair = EMPTY;
       } while (TRUE);
}


int main(){
int i = 0;

for(i = 0;i < N; i++){
	int x;
   scanf("%d",&x);
   sem_init(&(chair[i]),0,x);
}

i=0;
for(i=0;i < N;i++){
  customer(i);
}

return 0;
}
