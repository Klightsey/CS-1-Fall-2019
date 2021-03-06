// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
#include "GlobalsConstants.h"

using namespace std;


int main()
{
	int option = 0;
	string players[ROWS][COLS];			//array of 100 players, 3 columns
	initArray(players);					//initialize the array to all empty strings
	
	do
	{ 
		option = Display_Menu();		//display the menu and get user selection
		int x;
		switch (option)
		{
		case 1:
			initArray(players);
			Banner("Array Initialized");
			break;
		case 2:
			initArray(players);			//initialize the array, wipe out previous data
			loadData(players);			//load data from file into the array
			break;
		case 3:							
			enterPlayers(players);		//get player information from user into the array
			break;
		case 4:	
			displayAll(players);		//display a list of all players
			break;
		case 5:
			displaySelected(players);	//display data for selected player
			break;
		case 6:
			sortArray(players);			//sort array on last name
			break;
		case 7:
			saveData(players);			//save array data to file
			break;
		case 8:
			displayAppStatus(players);
			break;
		case 9:
			break;
		}
	} while (option > 0 && option < 9);
}