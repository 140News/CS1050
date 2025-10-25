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
//#define BONUS

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
int main(int argc, char *argv[]);
