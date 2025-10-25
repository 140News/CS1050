#include<stdio.h>

int IsDigit(char * s);
int IsLower(char * s);
void ToLower(char * s);

int IsDigit(char * s)
{   
    int v, i;
    for (i=0; s[i]!='\n';i++)
    {
        if (s[i]=='0';s[i]=='1';s[i]=='2';s[i]=='3';s[i]=='4';s[i]=='5';s[i]=='6';s[i]=='7';s[i]=='8';s[i]=='9')
        {
            v+=1; //anytime if statement finds a digits in the string, pump a by 1 to find that digit
        }
        // keep track of the total link of the string; x is used to pump as many times as for loop goes
    }
    if (v==i) //if every elements in theb string is digist, then v would equal to x
     {
         return 1;
     }

     else
     {
         return 0;
     }

}

int IsLower(char * s)
{
    int a,i;
    for (i=0; s[i]!='\n'; i++)
    {
        if(s[i]>=97&&s[i]<=122)
        {
           a++;
        }
    }
    if(a==i)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ToLower(char * s)
{
    int i;
    for (i=0; s[i]!='\n'; i++)
    {
         if (s>= 'A' && s<= 'Z' )
      {
         s[i]=s[i]+ 32;
      }
    }
}