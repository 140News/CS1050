#include<stdio.h>
void GetPromptString(char *output);
void PromptAndgetinteger(char *prompt, int *output);
void GetProduct(int a, int b, int *product);
void GetRemainder(int a, int b, int *remainder);


int main(void)
{
    char promptA[31], promptB[31];
    int a, b, product, remainder;

   printf("\n\n");
   printf("***********************\n");
   printf("*   Welcome to Lab 6   *\n");
   printf("***********************\n");
   printf("\n\n");

   printf("Enter the prompt for a: ");
   GetPromptString(promptA);
   printf("Enter the prompt for b: ");
   GetPromptString(promptB);

   PromptAndgetinteger(promptA, &a);
   PromptAndgetinteger(promptB, &b);

   GetProduct(a,b,&product);
   printf("The product of %d and %d is %d\n",a,b,product);
   
   GetRemainder(a, b, &remainder);
   printf("The remainder of dividing %d by %d is %d\n",a,b,remainder);
   
   printf("\n\n");
   printf("***********************\n");
   
   return 0;
}

void GetPromptString(char *output)
{
    scanf("%s", output);
}

void PromptAndgetinteger(char *prompt, int *output)
{
    printf("%s", prompt);
    scanf("%d", output);
}

void GetProduct(int a, int b, int *product)
{
    *product=a*b;
}

void GetRemainder(int a, int b, int *remainder)
{
    *remainder=a%b;
}