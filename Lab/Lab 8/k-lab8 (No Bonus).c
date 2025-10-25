#include<stdio.h>

#define ALPHATEST1 "abcd67890efghijk123z"
#define UPPERTEST1 "AbCDefghijKLMNOpqrSTUVwxyZ"
#define UPPERTEST2 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int IsAlpha(char*s);
int IsUpper(char*s);
void ToUpper(char*s);


int main(void)
{
    char sUpperTest1[]= UPPERTEST1;
    char sUpperTest2[]= UPPERTEST2;
    
    if(IsAlpha(ALPHATEST1))
    {
        printf("ALPHATEST1 is all alpha\n");
    }

    else
    {
        printf("ALPHATEST1 is not all alpha\n");
    }

    
    if(IsUpper(sUpperTest1))
    {
        printf("UPPERTEST1 is all uppercase: %s\n", sUpperTest1);
    }
    else
    {
        ToUpper(sUpperTest1);
        printf("The upper case version of UPPERTEST1 is: %s\n", sUpperTest1);
    }


    if(IsUpper(sUpperTest2))
    {
        printf("UPPERTEST2 is all uppercase: %s\n", sUpperTest2);
    }

    else
    {
        ToUpper(sUpperTest2);
        printf("The upper case version of UPPERTEST2 is: %s\n", sUpperTest2);
    }

}

int IsAlpha(char*s)
{
    int v, i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65&&s[i]<=90&&s[i]>=97&&s[i]<=122)
        {
            v+=1;
        }
    }

    if(v==i)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsUpper(char*s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]<65||s[i]>90)
        {
            return 0;
        }

    }
    return 1;
}


void ToUpper(char*s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            s[i]=s[i]-32;
        }
    }
}
