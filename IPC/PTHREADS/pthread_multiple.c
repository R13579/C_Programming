
#include "../header.h"


long long sum=0;

void* SUMMER(void *arg)
{
long long *ptr_arg=arg;
long long limit = *ptr_arg;
for(int i=0;i<=limit;i++)
{
	sum+=i;

}

pthread_exit(0);
}




int main(int argc , char *argv[])
{
if(argc < 3){

printf("Usage is %s <num> \n",argv[0]);
exit(-1);
}

int num_thread=argc-1;
long long n = atoll(argv[1]);

pthread_t tid[num_thread];
for(int i=0;i<num_thread;i++)
{
	pthread_attr_t attr;
pthread_attr_init(&attr);

pthread_create(&tid[i],&attr,SUMMER,&n);
}
for(int i=0;i<num_thread;i++)
{
pthread_join(tid[i],NULL);
}
printf("SUM is : %lld\n",sum);


}


