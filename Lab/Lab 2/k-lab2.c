#include<stdio.h>
int main(void)
{
int A,B;
printf("Enter two integers separated by spaces:");
scanf("%d%d",&A,&B);
if(B==0){
printf("The second integer may not be zero.Pleaswe enter it again:");
scanf("%d",&B);}
printf("***Initial Values***\n");
printf("A=%d\n",A);
printf("B=%d\n",B); 
printf("***Calculated Values***\n");
printf("A plus B=%d\n",(A+B));
printf("A minus B=%d\n",(A-B));
printf("A times B=%d\n",(A*B));
printf("A divided by B=%d\n",(A/B));
printf("A divided by B remainder=%d\n",(A%B));

return 1;

}
