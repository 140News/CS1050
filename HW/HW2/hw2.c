/*****************************************************************************
 * CS1050
 * Spring 2019
 * Mizzou Accomodations Reservation System (MARS)
 *****************************************************************************/
#include <stdio.h>

// NOTE! - Uncomment the following line if you want to do the bonus
//#define BONUS

// Symbolic constants and enums
#define COUNTHOTELS 6									
#define COUNTROOMTYPES 5									
#define STRINGMAX 64

#ifdef BONUS
enum HOTEL {Marriott, Hilton, BestWestern, HolidayInn, Motel6, Super8};
enum ROOM {StandardKing, Standard2Queen, QueenSuite, KingSuite, PresidentialSuite};
#endif

// Globals
const char const hotelNames[COUNTHOTELS][STRINGMAX] = {"Marriott", "Hilton", "Best Western", "Holiday Inn", "Motel 6", "Super 8"};
const char const roomNames[COUNTROOMTYPES][STRINGMAX] = {"Standard King", "Standard Two Queens", "Suite Two Queens", "Suite King", "Suite Presidential"};

int costMatrix[COUNTHOTELS][COUNTROOMTYPES]= 
{
	{200,200,350,375,550},	// Marriott
	{180,210,325,350,600},	// Hilton
	{125,125,240,250,400},	// Best Western
	{130,135,250,275,450},	// Holiday Inn
	{119,119,239,249,399},	// Motel 6
	{118,118,240,247,389},	// Super 8
};

/***********************************************************/
/* Prototypes                                              */
/***********************************************************/
#ifdef BONUS
// GetHotelName - Given a hotel value, return a printable string
const char * const GetHotelName(enum HOTEL hotel);
// GetRoomName - Given a room value, return a printable string
const char * const GetRoomName(enum ROOM room);
// GetRoomPrice - Returns the price of a room at a particular hotel
int GetRoomPrice(enum HOTEL hotel, enum ROOM room);
// PrintHotelRoomsByHotel - Print rooms and prices at a given hotel
void PrintHotelRoomsByHotel(enum HOTEL hotel);
// PrintHotelsByRoom - Print hotels and prices for a given room type
void PrintHotelsByRoom(enum ROOM room);
// getMainMenuChoice - Display the main men
#else
const char * const GetHotelName(int hotel);
const char * const GetRoomName(int room);
int GetRoomPrice(int hotel, int room);
void PrintHotelRoomsByHotel(int hotel);
void PrintHotelsByRoom(int room);
#endif

// PrintHotelOptions - Prints a numbered list of hotels
void PrintHotelOptions();
// PrintRoomOptions - Prints a numbered list of room types
void PrintRoomOptions();
// PrintHotelRoomsLessThan - Prints rooms at all hotels that are priced less than some limit
void PrintHotelRoomsLessThan(int iLimit);
int getMainMenuChoice();
/***********************************************************/

int main(void)
{
	printf("***** Welcome to the Mizzou Accommodations Reservation System (MARS)*****\n\n");
    int priceiLimit=0;
    while (1)
    {
            int option=getMainMenuChoice();
            switch (option)
            {
                case 1:
                PrintHotelOptions();
                break;

                case 2:
                PrintRoomOptions();
                break;

                case 3:
                PrintHotelRoomsLessThan(priceiLimit);
                break;

                case 4:
                printf("***** Thank you for using MARS! *****\n");
                return 0;
                break;

                default:
                option=getMainMenuChoice();
                break;

            }
		
    }
}
int getMainMenuChoice()
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
	    printf("Please make a selection:");
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

void PrintHotelOptions()
{
        int B;
        printf("1. Marriott\n");
        printf("2. Hilton\n");
        printf("3. Best Western\n");
        printf("4. Holiday Inn\n");
        printf("5. Motel 6\n");
        printf("6. Super 8\n");
        printf("Select a hotel:");
        scanf("%d",&B);
        if(B!=1&&B!=2&&B!=3&&B!=4&&B!=5&&B!=6)
            {
                printf("*** Error: choice out of range\n\n");
            }
        else 
        {
         printf("\n\n*** Rooms at %s : ",GetHotelName(B-1));
         PrintHotelRoomsByHotel(B-1);   
         printf("\n");
        }
    
}
void PrintHotelRoomsByHotel(int hotel)
{
    int i;
    for (i=0;i<COUNTROOMTYPES;++i)
    {
      printf("\n%s - %s($%d)",GetHotelName(hotel),GetRoomName(i),GetRoomPrice(hotel,i));
    }
}

void PrintRoomOptions()
{
    int C;
	printf("1. Standard King\n");
	printf("2. Standard Two Queens\n");
	printf("3. Suite Two Queens\n");
	printf("4. Suite King\n");
	printf("5. Suite Presidential\n");
	printf("Select a room:");
    scanf("%d",&C);
    if(C!=1&&C!=2&&C!=3&&C!=4&&C!=5)
    {
        printf("*** Error: choice out of range\n\n");
    }
    else
    {
        printf("\n\n*** Hotels with room %s : ",GetRoomName(C-1));
        PrintHotelsByRoom(C-1);
        printf("\n");
    }
}

void PrintHotelsByRoom(int room)
{
    int i;
    for (i=0;i<COUNTHOTELS;++i)
    {
        printf("\n%s - %s($%d)",GetHotelName(i),GetRoomName(room),GetRoomPrice(i,room));
    }
}

void PrintHotelRoomsLessThan(int iLimit)
{
	printf("Enter the maximum price in dollars you will pay:");
	scanf("%d", &iLimit);
    printf("\n");
	printf("*** Rooms less than $%d:\n", iLimit);
    
    for(int i=0;i<COUNTHOTELS;++i)
    {
    
        for(int j=0;j<COUNTROOMTYPES;++j)
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

int GetRoomPrice(int hotel, int room)
{
   return costMatrix[hotel][room];
}

const char * const GetHotelName(int hotel)
{
    return hotelNames[hotel];
}

const char * const GetRoomName(int room)
{
    return roomNames[room];
}

