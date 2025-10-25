#include<stdio.h>

int FillArrays(char FirstNames[][256], char LastNames[][256], float Avgs[], char*FileName);
void PrintArrays(char FirstNames[][256], char LastNames[][256], float Avgs[], int count);

int main(void)
{
    char FirstNames[9][256];
    char LastNames[9][256];
    float Avgs[9];
    char* FileName="labstats.dat";

    printf("\n\nToday's lineup:\n\n");
    int count=FillArrays(FirstNames, LastNames,Avgs,FileName);

    PrintArrays(FirstNames, LastNames, Avgs, count);
    printf("\n");

}

int FillArrays(char FirstNames[][256], char LastNames[][256], float Avgs[], char*FileName)
{
    FILE*cptr=fopen(FileName, "r");

    int count;
    fscanf(cptr,"%d",&count);
    

    int i;
    for (i=0;i<9;i++)
    {
         fscanf(cptr, "%s %s", FirstNames[i], LastNames[i]);
    }    
    for(i=0;i<9;i++)
    {
        fscanf(cptr, "%f", &Avgs[i]);
    }


    fclose(cptr);
    return count;
}

void PrintArrays(char FirstNames[][256], char LastNames[][256], float Avgs[], int count)
{
    for(int i=0; i<count; i++)
    {
       printf("%s %s %.3f\n", FirstNames[i],LastNames[i], Avgs[i]);
    }
}

