#include "header.h"
int globval=10;
int main( int argc , char *argv[] )
	{
		printf("helloExec\n");
	        printf("MY PID is %d\n",getpid());
        printf("The global val is %d:\n",globval); 
	printf("My Arguments");
for (int i=0;i<argc;i++)
{
printf("%s ",argv[i]);
printf("\n");
return 0;
}
}



