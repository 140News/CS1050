/*****************************************************************************
 * CS1050
 * Spring 2019
 * Mizzou Accomodations Reservation System (MARS)
 * By Jim Ries
 * March 3, 2019
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

// Prototypes
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


#ifdef BONUS
const char * const GetHotelName(enum HOTEL hotel)
#else
const char * const GetHotelName(int hotel)
#endif
{
	return hotelNames[hotel];
}

#ifdef BONUS
const char * const GetRoomName(enum ROOM room)
#else
const char * const GetRoomName(int room)
#endif
{
	return roomNames[room];
}

#ifdef BONUS
int GetRoomPrice(enum HOTEL hotel, enum ROOM room)
#else
int GetRoomPrice(int hotel, int room)
#endif
{
	return costMatrix[hotel][room];
}

void PrintHotelOptions()
{
	#ifdef BONUS
	enum HOTEL hotel;
	#else
	int hotel;
	#endif

	#ifdef BONUS
	for (hotel=Marriott; hotel<=Super8; hotel++)
	#else
	for (hotel=0; hotel<COUNTHOTELS; hotel++)
	#endif
	{
		printf("%d. %s\n",hotel+1,GetHotelName(hotel));
	}
}

void PrintRoomOptions()
{
	#ifdef BONUS
	enum ROOM room;
	#else
	int room;
	#endif

	#ifdef BONUS
	for (room=StandardKing;room<=PresidentialSuite;room++)
	#else
	for (room=0;room<COUNTROOMTYPES;room++)
	#endif
	{
		printf("%d. %s\n",room+1,GetRoomName(room));
	}
}

void PrintHotelRoomsLessThan(int iLimit)
{
	#ifdef BONUS
	enum HOTEL hotel;
	enum ROOM room;
	#else
	int hotel;
	int room;
	#endif

	printf("\n*** Rooms less than $%d:\n", iLimit);
	#ifdef BONUS
	for (hotel=Marriott; hotel<=Super8; hotel++)
	#else
	for (hotel=0; hotel<COUNTHOTELS; hotel++)
	#endif
	{
		#ifdef BONUS
		for (room=StandardKing; room<=PresidentialSuite; room++)
		#else
		for (room=0; room<COUNTROOMTYPES; room++)
		#endif
		{
			if (GetRoomPrice(hotel,room)<iLimit)
			{
				printf("%s - %s ($%d)\n",GetHotelName(hotel),GetRoomName(room),GetRoomPrice(hotel,room));
			}
		}
	}
}

#ifdef BONUS
void PrintHotelRoomsByHotel(enum HOTEL hotel)
#else
void PrintHotelRoomsByHotel(int hotel)
#endif
{
	#ifdef BONUS
	enum ROOM room;
	#else
	int room;
	#endif

	printf("\n*** Rooms at %s:\n", GetHotelName(hotel));
	#ifdef BONUS
	for (room = StandardKing; room <= PresidentialSuite; room++)
	#else
	for (room = 0; room < COUNTROOMTYPES; room++)
	#endif
	{
		printf("%s - %s ($%d)\n", GetHotelName(hotel), GetRoomName(room), GetRoomPrice(hotel, room));
	}
}

#ifdef BONUS
void PrintHotelsByRoom(enum ROOM room)
#else
void PrintHotelsByRoom(int room)
#endif
{
	#ifdef BONUS
	enum HOTEL hotel;
	#else
	int hotel;
	#endif

	printf("\n*** Hotels with room %s:\n", GetRoomName(room));
	#ifdef BONUS
	for (hotel = Marriott; hotel <= Super8; hotel++)
	#else
	for (hotel = 0; hotel < COUNTHOTELS; hotel++)
	#endif
	{
		printf("%s - %s ($%d)\n", GetHotelName(hotel), GetRoomName(room), GetRoomPrice(hotel, room));
	}
}


int getMainMenuChoice()
{
	int choice = -1;

	while (1 > choice || 4 < choice)
	{
		printf("\n\n*** Main Menu ***\n");
		printf("1. Display by hotel\n");
		printf("2. Display by room type\n");
		printf("3. Display by price limit\n");
		printf("4. Exit program\n");
		printf("\nPlease make a selection: ");
		scanf("%d",&choice);
		if (1 > choice || 4 < choice)
		{
			printf("\n*** Error: Please select a choice 1 - 4\n");
		}
	}

	return choice;
}

int main(void)
{
	int choice = -1;
	int maxprice;
	#ifdef BONUS
	enum HOTEL hotel;
	enum ROOM room;
	#else
	int hotel;
	int room;
	#endif

	printf("***** Welcome to the Mizzou Accommodations Reservation System (MARS) *****\n");

	while (4!=choice)
	{
		choice = getMainMenuChoice();
		switch(choice)
		{
			case 1:
				PrintHotelOptions();
				printf("Select a hotel: ");
				scanf("%d", (int *)&hotel);
				hotel--;
				#ifdef BONUS
				if (Marriott <= hotel && Super8 >= hotel)
				#else
				if (0 <= hotel && COUNTHOTELS > hotel)
				#endif
				{
					PrintHotelRoomsByHotel(hotel);
				}
				else
				{
					printf("*** Error: choice out of range\n");
				}
				break;

			case 2:
				PrintRoomOptions();
				printf("Select a room: ");
				scanf("%d", (int *)&room);
				room--;
				#ifdef BONUS
				if (StandardKing <= room && PresidentialSuite >= room)
				#else
				if (0 <= room && COUNTROOMTYPES > room)
				#endif
				{
					PrintHotelsByRoom(room);
				}
				else
				{
					printf("*** Error: choice out of range\n");
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

	printf("***** Thank you for using MARS! *****\n");
}
