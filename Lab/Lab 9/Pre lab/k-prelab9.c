#include<stdio.h>

int FillArrays(char Names[][256], float Avgs[], char*FileName);
void PrintArrays(char Names[][256], float Avgs[], int count);

int main(void)
{
    char Names[10][256];
    float Avgs[10];
    char*FileName="prelabstats.dat";//create a pointer point to the string

    printf("\n\nToday's lineup:\n\n");
    int count=FillArrays(Names,Avgs,FileName);//we return i-1
   
    PrintArrays(Names,Avgs,count);//count=number of lines, in print array
    printf("\n");

}

int FillArrays(char Names[][256], float Avgs[],char*FileName)
{
    FILE* ptr=fopen(FileName,"r");//create a file pointer, fopen returns the line we want to point to
    int i=0;
    while(!feof(ptr))//while the pointer is not at the null terminator line
    {
        fscanf(ptr, "%s %f", Names[i], &Avgs[i]);//fscanf is secifically for file
        i++;
    }
    fclose(ptr);
    return i-1;//it could be i or i-1
}

void PrintArrays(char Names[][256], float Avgs[], int count)
{   
    for(int i=0;i<count;i++)
    {
        printf("%s %.3f\n", Names[i], Avgs[i]);
    }
}
