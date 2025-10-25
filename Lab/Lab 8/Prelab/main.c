#include <stdio.h>


#define DIGITTEST1 "12345abcd67890"
#define DIGITTEST2 "1234567890"
#define LOWERTEST1 "hifromJimRies"
#define LOWERTEST2 "jimrieswashere"

int IsDigit(char * s);
int IsLower(char * s);
void ToLower(char * s);

int main(void)
{   
    char sLowerTest1[] = LOWERTEST1;
    char sLowerTest2[] = LOWERTEST2;
    
    if (IsDigit(DIGITTEST1))
    {
        printf("DIGITTEST1 is all digits\n");
    }
    else{
        printf("DIGITTEST1 is not all digits\n");
        }
    if (IsLower(sLowerTest1))
    {
        printf("LOWERTEST1 is all lower case: %s\n",sLowerTest1);
        }
    else
    {
        ToLower(sLowerTest1);
        printf("The lower case version of LOWERTEST1 is: %s\n",sLowerTest1);
    }
    if (IsLower(sLowerTest2))
    {
        printf("LOWERTEST2 is all lower case: %s\n",sLowerTest2);
    }
    else
    {
        ToLower(sLowerTest2);
        printf("The lower case version of LOWERTEST2 is: %s\n",sLowerTest2);
    }
}


