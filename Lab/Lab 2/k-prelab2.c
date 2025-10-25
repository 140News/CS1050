#include <stdio.h>
int main(void)
{
int A,B,C;
printf("Enter three integers separated by spaces:");
scanf("%d%d%d",&A,&B,&C);
if(A<0)
   A=A*-1;
if(B<0)
   B=B*-1;
if(C<0)
   C=C*-1;
printf("***Initial values***\n");
printf("A=%d\n",A);
printf("B=%d\n",B);
printf("C=%d\n",C);
printf("***Calculated values***\n");
printf("A plus B plus C=%d\n",(A+B+C));
printf("A times B times C=%d\n",(A*B*C));

return 1;

} 

