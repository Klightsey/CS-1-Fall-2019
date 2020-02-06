#pragma once
#include <string>
#include "GlobalsConstants.h"
using namespace std;

//Function declarations
int Display_Menu();
void enterPlayers(string array[ROWS][COLS]);
void initArray(string array[ROWS][COLS]);
int firstAvailableRow(const string array[ROWS][COLS]);
void saveData(const string array[ROWS][COLS]);
void loadData(string array[ROWS][COLS]);
void displayAll(const string array[ROWS][COLS]);
void displayAppStatus(const string array[ROWS][COLS]);
void displaySelected(const string array[ROWS][COLS]);
void sortArray(string array[ROWS][COLS]);
void swapRecords(string array[ROWS][COLS], int index);
void Banner(string message);



