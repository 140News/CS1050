#include<stdio.h>
#define LIMIT 10    

void InitArraySquare(int array[],int LIMIT)
{
    
    for (int i=0;i<LIMIT;i++)
    {
        array[i]=i*i;
    }
}
void IntArrayLinear(int array[],int LIMIT)
void PrintArray(int array[],int LIMIT)
{
    for(int i=0;i<LIMIT;i++)
    {
        printf("%d\n",array[i]);
    }
}

void SumArrays(int array1[],int array2[],int LIMIT)
{
    for(int i=0;i<LIMIT;i++)
    {
        printf("%d\n", array1[i]+array[i]);
    }
}

void MultArrays(int array1[],int array2[],int LIMIT)
{
    for(int i=0;i<LIMIT;i++)
    {
        printf("%d\n", array[i]*array2[i]);
    }
}

int main(void)
{

    printf("Array 1:%d\n",array[i]);
    
    printf("\n");
    printf("Array 2:%d\n",array[i]);

    printf("\n");
    printf("Sum of elements of arrays:%d\n",array[i]+array[i]);

    printf("\n");
    printf("Product of elements of arrays:\n"array[i]*array[i]);

    return 0;
}



