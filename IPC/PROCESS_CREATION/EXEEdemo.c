#include "header.h"


/**Exec replace the curently riunnning program wirh a brand new process
 **/
/**the main process is completely gone and the new process takes place we cant pass data inbetween these process*/

int globval=100;
int main( int argc , char *argv[] )
{
	
	printf("EXEC DEMO PID ID %d\n " , getpid());
	char *args[]={"./exec","Hello","World",NULL};
	execvp("./a.out",args);
	printf("\n\n\n********************\n\n\n");

	return 0;
}



