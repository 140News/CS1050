#include<stdio.h>

//Function to get prompt from the user for integer A and B
void GetPromptString(char *output)
{
   scanf("%s", output);
}

//Function to print the promt and get integer values from the user
void PromptAndGetInteger(char *prompt, int *output)
{
   printf("%s", prompt);
   scanf("%d", output);
}

//Function to find product of a and b and store it into product
void GetProduct(int a, int b, int *product)
{
   *product = a*b;
}

//Function to find remainder after dividing a by b and store it into remainder
void GetRemainder(int a, int b, int *remainder)
{
   *remainder = a%b;
}

int main(void)
{
   char promptA[31], promptB[31];
   int a, b, product, remainder;
   
   printf("**********************\n");
   printf("* Welcome to Lab 6   *\n");
   printf("**********************\n\n");
   
   printf("Enter the prompt for a: ");
   GetPromptString(promptA);
   printf("Enter the prompt for b: ");
   GetPromptString(promptB);
   
   PromptAndGetInteger(promptA, &a);
   PromptAndGetInteger(promptB, &b);
   
   GetProduct(a, b, &product);
   
   printf("The product of %d and %d is %d\n", a, b, product);
   
   GetRemainder(a, b, &remainder);
   
   printf("The remainder of dividing %d by %d is %d\n", a, b, remainder);
   
   printf("\n**********************\n");
   return 0;
}
