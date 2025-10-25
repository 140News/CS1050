/*****************************************************************************
 * CS1050
 * Spring 2019
 * Homework #3
 * Mizzou Accomodations Reservation System 2.0 (MARS 2.0)
 *****************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// Symbolic Constants
#define MAXNAME 256
// Uncomment the following line if you are doing the BONUS
#define BONUS

// Globals
int g_countHotels = 0;
int g_countRooms = 0;
#ifdef BONUS
char ** g_hotelNames;
char ** g_roomNames;
int ** g_costMatrix;
#else
#define MAX_HOTEL_NAMES 25
#define MAX_ROOM_TYPES 25
char g_hotelNames[MAX_HOTEL_NAMES][MAXNAME];
char g_roomNames[MAX_ROOM_TYPES][MAXNAME];
int g_costMatrix[MAX_HOTEL_NAMES][MAXNAME];
#endif


// Prototypes similar to HW2
const char * const GetHotelName(int hotel);
const char * const GetRoomName(int room);
void PrintHotelOptions();
void PrintRoomOptions();
void PrintHotelRoomsLessThan(int iLimit);
int GetMainMenuChoice();
int GetRoomPrice(int hotel, int room);
void PrintHotelRoomsByHotel(int hotel);
void PrintHotelsByRoom(int room);

// New Prototypes
int LoadHotelNames(char * sFileName);
int LoadRoomNames(char * sFileName);
int LoadCostMatrix(char * sFileName);
void PrintCostMatrix();
void PrintHotelNames();
void PrintRoomNames();

// This prototype for main should help you read command-line arguments
int main(int argc, char *argv[])
{   
    int choice=-1;
    int maxprice;
    int i, j;
    if (argc!=4)
    {
        printf("Error");
        return 0;
    }

    printf("***** Welcome to the Mizzou Accommodations Reservation System 2.0 (MARS2.0)*****\n");
    printf("Data Loading.....\n");

    int a;

    a=LoadHotelNames(argv[1]);
    if (a==0)
    {
        printf("Error: Data not load\n");
        return 0;
    }

    a=LoadRoomNames(argv[2]);
    if (a==0)
    {
        printf("Error: Data not load\n");
        return 0;
    }

    a=LoadCostMatrix(argv[3]);
    if(a==0)
    {
        printf("Error: Data not load\n");
        return 0;
    }

    PrintHotelNames();
    PrintRoomNames();
    PrintCostMatrix();

    printf("\nData loaded!\n\n");

    while(4!=choice)
    {
            choice=GetMainMenuChoice();
            switch (choice)
            {
                case 1:
                PrintHotelOptions();
                printf("Select a hotel: ");
                scanf("%d", &i);
                i--;
                if (0 <= i && g_countHotels > i)
				{
					PrintHotelRoomsByHotel(i);
				}
				else
				{
					printf("*** Error: choice out of range\n");
				}
                break;

                case 2:
                PrintRoomOptions();
                printf("Select a room: ");
				scanf("%d", &j);
				j--;
                if (0 <= j && g_countRooms> j)
                {
                    PrintHotelsByRoom(j);
                }
                break;

                case 3:
				printf("Enter the maximum price in dollars you will pay: ");
				scanf("%d", &maxprice);
				PrintHotelRoomsLessThan(maxprice);
				break;

                default:
                break;

            }
		
    }

     printf("***** Thank you for using MARS 2.0! *****\n\n");
}
//****************************************************
int LoadHotelNames(char * sFileName)
{
    FILE*cptr=fopen(sFileName, "r");

    if(cptr==NULL)
    {
        return 0;
    }

    fscanf(cptr, "%d", &g_countHotels);
    
    int i;
    g_hotelNames=(char **)malloc(g_countHotels * sizeof(char *));
    for(i=0;i<g_countHotels;i++)
    {   
        g_hotelNames[i]=(char*)malloc(MAXNAME * sizeof(char));
    }

    for(i=0;i<g_countHotels;i++)
    {   
        fscanf(cptr, "%s", g_hotelNames[i]);
    }

    fclose(cptr);
    return g_countHotels;
}
//***************************************************
int LoadRoomNames(char*sFileName)
{
    FILE*cptr=fopen(sFileName, "r");

    if(cptr==NULL)
    {
        return 0;
    }

    fscanf(cptr, "%d", &g_countRooms);

    int j;
    g_roomNames=(char **)malloc(g_countRooms * sizeof(char*));

    for(j=0;j<g_countRooms;j++)
    {
        g_roomNames[j]=(char*)malloc(MAXNAME * sizeof(char));
    }

    for(j=0;j<g_countRooms;j++)
    {
        fscanf(cptr, "%s", g_roomNames[j]);
    }

    fclose(cptr);
    return g_countRooms;
}
//***************************************************
int LoadCostMatrix(char*sFileName)
{
    FILE*cptr=fopen(sFileName, "r");

    if(cptr==NULL)
    {
        return 0;
    }

    int i, j;
    g_costMatrix=(int **)malloc(g_countHotels * sizeof(int*));
    for(i=0;i<g_countHotels;i++)
    {
        g_costMatrix[i]=(int*)malloc(g_countRooms * sizeof(int));
    }

    for(i=0; i<g_countHotels; i++)
    {
        for (j=0; j<g_countRooms; j++)
        {
            fscanf(cptr, "%d", &g_costMatrix[i][j]);
        }
    }

    fclose(cptr);
    return 1;
}
//***************************************************
void PrintCostMatrix()
{
    int i, j;
    printf("Cost Matrix:\n");
    printf("------------\n");
    for(i=0; i<g_countHotels;i++)
    {
        for(j=0; j<g_countRooms; j++)
        {
            printf("%s, %s = %d\n", g_hotelNames[i], g_roomNames[j], g_costMatrix[i][j]);
        }
    }
    printf("\n\n");
}
//***************************************************
void PrintHotelNames()
{
    int i;
    printf("Hotel Names:\n");
    printf("------------\n");
    for(i=0;i<g_countHotels;i++)
    {
        printf("%s\n", g_hotelNames[i]);
    }
    printf("\n\n");
}
//***************************************************
void PrintRoomNames()
{
    int j;
    printf("Room Names:\n");
    printf("------------\n");
    for(j=0;j<g_countRooms;j++)
    {
        printf("%s\n", g_roomNames[j]);
    }
    printf("\n\n");
}
//***********************************************************
int GetMainMenuChoice()
{
    int A;
	while(1)
    {
        printf("\n");
        printf("*** Main Menu ***\n");
	    printf("1. Display by hotel\n");
	    printf("2. Display by room type\n");
	    printf("3. Display by price limit\n");
	    printf("4. Exit program\n\n");
	    printf("Please make a selection: ");
	    scanf("%d",&A);
	    if(A!=1&&A!=2&&A!=3&&A!=4)
            {
                printf("\n");
                printf("*** Error: Please select a choice 1 - 4\n\n");
                printf("\n");
				continue;
            }
        else break;
        
    }
    return A;
}
//***************************************************
void PrintHotelOptions()
{
        int i;
        for(i=0;i<g_countHotels;i++)
        {
            printf("%d. %s\n", i+1, GetHotelName(i));
        }
    
}
//***************************************************
void PrintHotelRoomsByHotel(int hotel)
{
    int j;
    printf("\n");
    printf("*** Rooms at %s\n", GetHotelName(hotel));
    for (j=0;j<g_countRooms;j++)
    {
      printf("%s - %s ($%d)\n",GetHotelName(hotel), GetRoomName(j),GetRoomPrice(hotel, j));
    }
}
//***************************************************
void PrintRoomOptions()
{
    int j;
    for(j=0;j<g_countRooms;j++)
    {
        printf("%d. %s\n", j+1, GetRoomName(j));
    }
}
//***************************************************
void PrintHotelsByRoom(int room)
{
    int i;
    printf("\n");
    printf("*** Hotels with Room %s:\n", GetRoomName(room));
    for (i=0;i<g_countHotels;i++)
    {
        printf("%s - %s ($%d)\n",GetHotelName(i),GetRoomName(room),GetRoomPrice(i, room));
    }
}
//***************************************************
void PrintHotelRoomsLessThan(int iLimit)
{
	printf("\n*** Rooms less than $%d:\n", iLimit);
    
    for(int i=0;i<g_countHotels;++i)
    {
    
        for(int j=0;j<g_countRooms;++j)
        {
            int Price=GetRoomPrice(i,j);
            if(Price<iLimit)
            {
                const char * const firstrow=GetHotelName(i);
                const char * const secondrow=GetRoomName(j);
                printf("%s - %s ($%d)\n", firstrow, secondrow, Price);
            }
        }
    }
}
//***************************************************
int GetRoomPrice(int hotel, int room)
{
   return g_costMatrix[hotel][room];
}
//***************************************************
const char * const GetHotelName(int hotel)
{
    return g_hotelNames[hotel];
}
//***************************************************
const char * const GetRoomName(int room)
{
    return g_roomNames[room];
}
//***************************************************
