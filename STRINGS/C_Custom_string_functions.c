#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int c_strlen(char *dst)
{
    int c=0;
    while((*dst++)!='\0')
    {
        c++;
   //     printf("1");
    }
    return c;
}

char *c_strcat(char *dst , const char *src)
{
    char *temp=dst;
    
    temp=temp+c_strlen(dst);
    while((*src)!='\0')
    {
        *temp++=*src++;
 //       printf("!");
    }
    *temp='\0';
    return dst;
}
char *c_strncat(char *dst , const char *src,int num)
{
  char *i_dst=dst;
  dst=dst+c_strlen(dst);
  while(*src && num--)
  {
      *dst++=*src++;
  }
  *dst='\0';
  return i_dst;
}
char *c_strchr(char *dst , char key)
{
    while(*dst!='\0')
    {
        printf("%c:::%c\n",*dst,key);
        if(*dst==key)
        {
            return dst;
        }
        dst++;
    }
    return NULL;
}
char *strchr42a(char *str, int ch)
{
do      {
        if (*str == ch) return str;
        } while (*str++) ;
return NULL;
}

int c_strncmp(char *a,char *b,int n)
{
    while(*a && n--)
    {
        if( (*a==*b) || (*a^32)==*b )
        {
            a++;
            b++;
        }
        else 
        break;
        
    }
    printf(" %c %c",*a,*b);
    return (*b-*a);
    
}


int c_strcmp(const char *a,const char *b)
{
    while(*a)
    {
        if( (*a==*b) || ((*a^32)==*b) )
        {
            a++;
            b++;
        }
        else
        {
            break;
        }
    }
    printf(" the values were %c %c ",*a,*b);
    return ((*b-*a));
}
char *c_strcpy(char *dst,char *src)
{
    int dst_src=c_strlen(dst);
    char *i_dst=dst;
    //dst=dst+dst_src;
    while(*src)
    {
        *dst++=*src++;
    }
    *dst='\0';
    return i_dst;
}
char *c_strncpy(char *dst,char *src,int n)
{
    int dst_src=c_strlen(dst);
    char *i_dst=dst;
    //dst=dst+dst_src;
    while(*src && n-- )
    {
        *dst++=*src++;
    }
    *dst='\0';
    return i_dst;
}

int main()
{
    char a[10]="QWE";
    char b[10]="ABCDEFG";

    
    char v='B';


     
    printf("%s\n",strcat(a,b));

    
   // printf("%s : %s : %s",c_strchr(a,v),strchr(a,'B'),strchr42a(a,v));
    char c[20]="ABCDEFG";
    char d[10]="ABCdEFGH";
    //printf("\n%d : %d : %d",strcmp(c,d),strcmp(c,d),strcmp(c,d));
    printf("\n\n\n\n");
    printf("\n\n\n\n diff is %d",c_strcmp(c,d));
    printf("copied %s\n",c_strcpy(c,d));
    //printf("%s",c_strncat(c,d,5));
   // printf("%d",c_strncmp(c,d,8));
    printf("copied %s\n",c_strncpy(c,d,5));
    printf("");
    return 1;
}

