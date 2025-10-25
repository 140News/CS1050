#include <stdio.h>
#define ARRAY_SIZE 10

int FillArray(int array[],int size)
{
    int curSize=0;

    //curSize maintains the current number of elements in the array
    //curSize保持当前数组中元素的数量

    for (int i=0;i<size;i++)
    {
        printf("Enter value for array element %d:\n",i);
        scanf("%d",&array[i]);
        if (array[i]==-1)
        {
            return curSize;
        }

        //This statement gets executed if the entered element is not equal to -1
        //如果输入的元素不等于-1，则执行该语句

        curSize++;
    }
    return curSize;
}
int DisplayMenu()
{
    printf("\n");
    printf("Select a function:\n1.Sum;\n2.Product.\nEnter -1 to exit\n");
    int option;
    scanf("%d",&option);
    return option;
}

int Sum(int array[],int size)
{
    int curSum=0;

    //curSum maintains the current sum of the array elements
    //curSum保持数组元素当前的和

    for(int i=0;i<size;i++)
    {
        curSum=curSum+array[i];
    }
    return curSum;
}

int Product(int array[],int size)
{
    int curProduct=1;

    //curProduct maintains the current product of the array elements
    //curProduct保持数组元素当前的乘积

    for(int i=0;i<size;i++)
    {
        curProduct=curProduct*array[i];
    }
    return curProduct;
}

int main(void)
{
    printf("Welcome to the Array Operations Program!\n\n");
    int array[ARRAY_SIZE];
    int SizeOfArray=FillArray(array,ARRAY_SIZE);
    while(1)
    {
        int option=DisplayMenu();
        if(option==-1)
        {
            break;
        }
        else if(option==1)
        {
            int sum=Sum(array,SizeOfArray);
            printf("Sum=%d\n",sum);
        }
        else if(option==2)
        {
            int product=Product(array,SizeOfArray);
            printf("Product=%d\n",product);
        }
    }
    printf("\n");
    printf("Thanks for using the Array Operations Program!\n");
    return 1;

}
