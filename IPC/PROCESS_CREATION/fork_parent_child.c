#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	/**FORK takes a process and spawns a child process from it
	 **/
	printf(" I am %d:\n",getpid());
	pid_t pid=fork();
	printf("fork returned:%d\n",(int) pid);

	if(pid < 0 )
	{
		perror("FORK Failed");
	}
	if(pid==0)
	{
		for(int i=0;i<16 ; i++)
		{
			if(i % 2 ==0)
			 
			{
				sleep(1);
				 printf("%d : %d\n",getpid(),i);
			}
		}

		printf("I am the child with pid = %d\n",getpid());
		exit(0);
	}
	else if(pid > 0)
	{
	
		for(int i=0;i<10 ; i++)
		{
			if(i % 2 ==1)
			 {
				 sleep(1.5);
				 printf("\t\t%d : %d\n",getpid(),i);
			}
		}
		printf(" I am the parent : %d\n",getpid());
	
	}
	printf("I am the paresnt witing on child");
	wait(NULL);

	return 0;
}



