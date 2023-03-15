#include "../../header.h"


long long limit=1000000;
long long sum=0;

//sem_t s;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *summer( void * arg)
{
long long val = *(int *)arg;
long long temp;
for(long long i=0;i<limit;i++)
{
//pthread lock
//	pthread_mutex_lock(&mutex);
//	sem_wait(&s);
        temp=val;
	temp=val;
	sum+=val;
//	pthread_mutex_unlock(&mutex);
//	sem_post(&s);
//pthread unlock
}

}

int main()
{
long long val[4];
val[0]=val[2]=1;
val[1]=val[3]=-1;

//sem_init(&s,0,1);
int tc=4;
pthread_t tid[tc];
for(int i=0;i<tc;i++)
{
pthread_create(&tid[i],NULL,summer,&val[i]);
}
for(int i=0;i<tc;i++)
{
pthread_join(tid[i],NULL);
}

printf("%lld",sum);
return 1;


}
