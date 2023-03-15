#include<stdio.h>




long long int atoi(char *s)
{
long long int a=0;
while(*s)
{
	a=a*10+*s-'0';
	s++;

}
return a;
}
int main()
{
char s[]="123456789123";
long long int a=atoi(s);

printf("%lld",a);
}
