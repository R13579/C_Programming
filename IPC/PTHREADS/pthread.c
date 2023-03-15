
#include "header.h"


long long sum=0;

void* SUMMER(void *arg)
{
long long *ptr_arg=arg;
long long limit = *ptr_arg;
for(int i=0;i<limit;i++)
{
	sum+=i;

}

pthread_exit(0);
}




int main(int argc , char *argv[])
{
if(argc < 2){

printf("Usage is %s <num> \n",argv[0]);
exit(-1);
}

long long n = atoll(argv[1]);

pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid,&attr,SUMMER,&n);
pthread_join(tid,NULL);
printf("SUM is : %lld\n",sum);


}



