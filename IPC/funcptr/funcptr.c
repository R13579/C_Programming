
#include "header.h"


int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
return a-b;	
	
}
int mul(int a,int b)
{
return a*b;

}
int divi(int a,int b)
{
	return a%b;
}




int (*fp[4])(int x , int y)={add,sub,mul,divi};

int main()
{
int a=5,b=10;

for(int i=0;i<4;i++)
{
printf("%d  \n" , (*fp[i])(a, b));
}
return 1;
}
