#include<stdio.h>
#include<math.h>
double Power(double base,int exponent);
void DoTest(double base,int exponent);
int main(void)
{
    printf("** Welcome to the Power Calculation Test Program **\n\n");

    DoTest(1,1);
    DoTest(2,2);
    DoTest(1.05,10);
    DoTest(1.05,100);
    DoTest(-1,2);
    DoTest(-1.05,10);
    DoTest(5,101);
    DoTest(5.3,0);
    DoTest(5.7,-1);
}

double Power(double base,int exponent)
{
    switch(exponent){
        case 0:
        break;
    
        default:
        return(base*Power(base,exponent));
    }
        return 1;
}

void DoTest(double base,int exponent)
{
    double A;
    double B;
    printf("* Test Power(%f,%d)",base,exponent);
    A=pow(base,exponent);

    if(exponent<=0||exponent>100)
        exponent=1;              
        B=Power(base,exponent);

    if(A==B)
        printf(" Succeeded! *\n");
    else
        printf(" Failed. *\n");
    return;
}
