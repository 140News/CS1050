#include <stdio.h>
#include <stdlib.h>

struct _Player
{
    char FirstName[24];
    char LastName[24];
    float avg;
};

int FillArrays(struct _Player * players, char * filename);
void PrintArrays(struct _Player * players, int count);

int main(void)
{
    struct _Player *players = malloc(25 * sizeof(struct _Player));
    int count=FillArrays(players, "prelab10stats.dat");
    printf("**** Team Batting ****\n\n");
    printf("First Name          Last Name           Batting Average\n");
    printf("----------          ---------           ---------------\n");
    PrintArrays(players, count);
    return 0;

}

int FillArrays(struct _Player * players, char * filename)
{
   FILE* ptr=fopen(filename, "r");
   int i=0;
   while(!feof(ptr))
   {
       fscanf(ptr,"%s %s %f", players[i].FirstName, players[i].LastName, &players[i].avg);
       i++;
   }

   fclose(ptr);
   return i-1;
}

void PrintArrays(struct _Player * players, int count)//consistance when sending player, it would not recohnize baseball
{
    for(int i=0; i<count; i++)
    {
        printf("%s %-6s %-6.3f\n", players[i].FirstName, players[i].LastName, players[i].avg);
    }
}

