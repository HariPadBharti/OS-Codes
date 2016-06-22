

#include<pthread.h> 
#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 
using namespace std; 
string s,s1; 
int total=0; 
int t=0;

void * calcsub (void * p) 
{ 

	int a=*((int*)p);
	int l=(s.length()/2)+(a); 
	int tillnow=0; 
	for(int i=(a);i<l;i++) 
	{ 
		if(s1==s.substr(i,s1.length())) 
		tillnow++; 
	} 
	total+=tillnow; 
	printf("thread %d found %d occurences\n",++t,tillnow); 
	pthread_exit(NULL); 

}

int main() 
{ 
	getline(cin, s); 
	cin>>s1; 
	int l=0; 
	pthread_t p[2];

	//dividing string into 2 halves 

	pthread_create(&p[0],NULL,calcsub,(void *)&l); 
	int l1=(s.length())/2; 
	pthread_create(&p[1],NULL,calcsub,(void *)&l1); 
	pthread_join(p[0],NULL); 
	pthread_join(p[1],NULL); 
	cout<<"total occurences="<<total<<endl; 
	return 0; 
}






//input:
/*
Hello we are doing pthread testing with string
in
*/

//output
/*
thread 1 found 1 occurences
thread 2 found 2 occurences
total occurences=3
*/
