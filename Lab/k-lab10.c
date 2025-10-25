#include<stdio.h>
#include<stdlib.h>

struct _Player
{
    char FirstName[15];
    char LastName[15];
    float Avgs;
    float Pcts;
};

int FillArrays(struct _Player * players, int count, char* filename);
void PrintArrays(struct _Player * players, int count);

int main(int argc, char *argv[])
{   if(argc!=3)
    {
        printf("count_of_records_to_process data_file_name\n");
    }
    int count=atoi(argv[1]);
    struct _Player *players = malloc(count * sizeof(struct _Player));
    

    count= FillArrays(players, count, argv[2]);


    printf("**** Team Batting ****\n\n");
    printf("First Name        Last Name  Batting Average      On-Base Pct\n");
    printf("----------        ---------  ---------------      -----------\n");
    
    PrintArrays(players,count);
    return 0;
}

int FillArrays(struct _Player * players, int count, char *filename)
{
    FILE* cptr=fopen(filename, "r");
    

    int i; 
    for(i=0;i<count;i++)
    {
        if(feof(cptr))
        {
            break;
        }
            fscanf(cptr, "%s %s %f %f\n", players[i].FirstName, players[i].LastName, &players[i].Avgs, &players[i].Pcts);
        
     }   

    fclose(cptr);
    return i;
}

void PrintArrays(struct _Player *players, int count)
{
    for(int i=0; i<count; i++)
    {

        printf("%10s %16s %16.3f %16.3f\n", players[i].FirstName, players[i].LastName, players[i].Avgs, players[i].Pcts);
    }
}
