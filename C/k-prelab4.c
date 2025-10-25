#include<stdio.h>
#include<math.h>
double Power(double base,double exponent);
double DoTest(double base,double exponent);
int main(void)
{
printf("** Welcome to the Power Calculation Test Program **\n\n");
DoTest(1,1);
DoTest(2,2);
DoTest(1.05,10);
DoTest(1.05,100);
DoTest(-1,2);
DoTest(-1.05,10);
DoTest(5,105);
DoTest(5.3,0);
DoTest(5.7,-1);
}
double Power(double base,double exponent)
{
if (exponent!=0)
{
return (base*Power(base, exponent-1));
}
else{
return 1;
}
}
double DoTest(double base,double exponent)
{
double M_Value;
double P_Value;
printf("* Test Power(%f,%.0f) ",base,exponent);
M_Value=pow(base,exponent);
if(exponent>100||exponent<=0)
exponent=1;
P_Value=Power(base,exponent);
if(M_Value==P_Value)
printf("Succeeded! *\n");
else
printf("Failed.*\n");
return 1;
}
