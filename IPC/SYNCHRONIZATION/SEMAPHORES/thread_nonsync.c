#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h> 
void *fun1();
void *fun2();
long long looptime=1000000;
long long shared=1; //shared variable
sem_t s; //semaphore variable
int main()
{
sem_init(&s,0,1); //initialize semaphore variable - 1st argument is address of variable, 2nd is number of processes sharing semaphore, 3rd argument is the initial value of semaphore variable
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);
	          
printf("Final value of shared is %lld\n",shared); //prints the last updated value of shared variable

}












void *fun1()
{
	   
       
long long  x;

for(long long i=0;i<looptime;i++)
{
//sem_wait(&s); //executes wait operation on s

x=shared;//thread1 reads value of shared variable

printf("Thread1 reads the value as %lld\n",x);

x++;  //thread1 increments its value

printf("Local updation by Thread1: %lld\n",x);

//sleep(1); //thread1 is preempted by thread 2

shared=x; //thread one updates the value of shared variable
			                                  
printf("Value of shared variable updated by Thread1 is: %lld\n",shared);    

//sem_post(&s);
//sleep(1);
}
}







void *fun2()
{
	    long long  y;
for(long long  i=0;i<looptime;i++)
{
//	    sem_wait(&s);
	    y=shared;//thread2 reads value of shared variable
	    printf("\t\tThread2 reads the value as %lld\n",y);
	    y--;  //thread2 increments its value
	    printf("\t\tLocal updation by Thread2: %lld\n",y);
	    //sleep(1); //thread2 is preempted by thread 1
	    shared=y; //thread2 updates the value of shared variable
	    printf("\t\tValue of shared variable updated by Thread2 is: %lld\n",shared);
//	    sem_post(&s);
//	    sleep(2);
}
	                           
}
