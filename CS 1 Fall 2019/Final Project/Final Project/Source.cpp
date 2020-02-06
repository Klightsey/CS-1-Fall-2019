#include "functions.h"
#include "GlobalsConstants.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

string OpenFileName = "";

//************************************************
//Function to display a message and prompt user to continue
//************************************************
void Banner(string message)
{
	string unpause;
	cout << endl << endl << "\t*****" << endl;
	cout << "\t" << message << endl;
	cout << "\t*****" << endl << endl;
	cout << "\tENTER to Continue";
	cin.ignore();
	getline(cin, unpause);
}

//************************************************
//Function to initialize the array to all empty strings
//************************************************
void initArray(string array[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)		//walk through the rows
	{
		for (int j = 0; j < COLS; j++)	//walk through the columns
		{
			array[i][j] = "";			//insert empty string in element
		}
	}
}

//************************************************
//Function to find the first available element in the array
//************************************************
int firstAvailableRow(const string array[ROWS][COLS])
{
	int availRow = 0;
	int count = 0;
	while (array[count][FNAME] != "")		//while Firstname column is used, go to next one
	{
		count++;
	}
	return count;							//return first unused row in the array
}

//************************************************
//Function to get player information from the user and save it in the array
//************************************************
void enterPlayers(string array[ROWS][COLS])
{
	string fName, lName, jerseyNum = "";			//initialize variables
	int currRow = firstAvailableRow(array);			//find first available row in the array
	while (fName != "Exit")							//loop until user enters "Exit"
	{
		cout << "Enter Players First Name (Exit): ";
		cin >> fName;								//get First Name
		if (fName != "Exit")						//check to see if it is "Exit"
		{
			cout << "Enter Players Last Name: ";	//if NOT, get Last name and Jersey Number
			cin >> lName;
			cout << "Enter Players Jersey Number: ";
			cin >> jerseyNum;

			array[currRow][FNAME] = fName;				//save player info to the array ar currRow index
			array[currRow][LNAME] = lName;
			array[currRow][JNUM] = jerseyNum;
			currRow++;									//increment to next row
		}
	}
}

//************************************************
//Function to display menu and return user choice
//************************************************
int Display_Menu()
{
	system("CLS");			//only works on Windows OS
	//display menu options
	int option;
	cout << endl << "\tWelcome to My Team Application" << endl << endl;
	cout << "\t1 ... Initialize Application" << endl;
	cout << "\t2 ... Load Data" << endl;
	cout << "\t3 ... Enter New Player" << endl;
	cout << "\t4 ... Display All Players" << endl;
	cout << "\t5 ... Display ONE PLayer" << endl;
	cout << "\t6 ... Sort Players by Last Name" << endl;
	cout << "\t7 ... Save All Data" << endl;
	cout << "\t8 ... Application Status" << endl;
	cout << "\t9... Quit Application" << endl;
	cout << "\n\tChoose: ";
	cin >> option;			//get the user's choose
	cout << endl;
	return option;			//return choice
}

//************************************************
//Function to save all data from array to file
//************************************************
void saveData(const string array[ROWS][COLS])
{
	ofstream outFile;
	string filename;
	int lastValidRow;
	lastValidRow = firstAvailableRow(array);					//find last valid data row in array

	cout << "Enter the name of the file for saving all data: ";
	cin >> filename;
	outFile.open("C:\\mydata\\" + filename);					//open file using user input name

	while (!outFile)											//verify that the file was created and opened
	{
		cout << "Could not create file. Enter the name of the file for saving all data: ";
		cin >> filename;
		outFile.open("C:\\mydata\\ + filename");				//open file using user input name
	}
	if (lastValidRow > 0)										//verify that there is data to write
	{
		for (int i = 0; i < lastValidRow; i++)
		{
			outFile << array[i][FNAME] << " " << array[i][LNAME] << " " << array[i][JNUM] << endl;		//write data items to file with space seperators
		}
	}
	outFile.close();
	Banner("Data saved to " + filename);
}

//************************************************
//Function to load data from file into array
//************************************************
void loadData(string array[ROWS][COLS])
{
	ifstream inFile;
	string filename;
	int rowCount = 0;
	string fname, lname, jerseyNum;

	cout << "Enter the name of the input file: ";
	cin >> filename;
	inFile.open("C:\\mydata\\" + filename);

	OpenFileName = filename;							//saved in global variable for use in other functions (displayAppStatus)

	while (!inFile)
	{
		cout << "File NOT Found. Enter the name of the input file: ";
		cin >> filename;
		inFile.open("C\\mydata\\" + filename);
	}
	
	while (rowCount < ROWS && inFile >> fname)			//read data from file and store in the array
	{
		inFile >> lname;
		inFile >> jerseyNum;

		array[rowCount][FNAME] = fname;
		array[rowCount][LNAME] = lname;
		array[rowCount][JNUM] = jerseyNum;
		rowCount++;
	}
	inFile.close();
	if (rowCount > ROWS - 1)
	{
		Banner("Maximum size of 'in Memory' data was exceeded. Please adjust the size of the storage array");
	}
	Banner("Data Loaded from file: " + filename + "\n\t  Records Loaded:  " + to_string(rowCount));
}

//************************************************
//Function to display all players in the array
//************************************************
void displayAll(const string array[ROWS][COLS])
{
	int lastRecord = firstAvailableRow(array);
	string unpause;
	cout << endl << "***********************************" << endl;
	cout << "\tList of All Players" << endl;
	cout << "***********************************" << endl;

	for (int i = 0; i < lastRecord; i++)
	{
		cout << array[i][FNAME] << "\t" << array[i][LNAME] << ":\t" << array[i][JNUM] << endl;
	}
	cout << "***********************************" << endl;
	cout << "\tList of All Players" << endl;
	cout << "***********************************" << endl << endl;
	cout << "Enter E to Exit  ";
	cin >> unpause;

}

//************************************************
//Function to display the status of the application
//************************************************
void displayAppStatus(const string array[ROWS][COLS])
{
	system("CLS");
	cout << endl << "\tRecord Count: " << firstAvailableRow(array) << endl;
	cout << "\tOpen File Name: " << OpenFileName << endl;
	Banner("Application Status");
}

//************************************************
//Function to locate and display information about one player
//************************************************
void displaySelected(const string array[ROWS][COLS])
{
	string lastName;
	int currentRow = 0;
	cout << "Enter player to display(last name, must be exact match): ";
	cin >> lastName;

	while (lastName != array[currentRow][LNAME]);
	{
		currentRow++;
	}

	cout << endl << array[currentRow][FNAME] << "\t" << array[currentRow][LNAME] << ":\t" << array[currentRow][JNUM] << endl;
	Banner("");
}

//************************************************
//Function to swap two records in the array
//************************************************
void swapRecords(string array[ROWS][COLS], int index)
{
	//Step 1 - Save the data from the first row
	string tmpFNAME = array[index][FNAME];
	string tmpLNAME = array[index][LNAME];
	string tmpJNUM = array[index][JNUM];

	//Step 2 - Move second item into first item
	array[index][FNAME] = array[index + 1][FNAME];
	array[index][LNAME] = array[index + 1][LNAME];
	array[index][JNUM] = array[index + 1][JNUM];

	//Step 3 - Move temp data into second item
	array[index + 1][FNAME] = tmpFNAME;
	array[index + 1][LNAME] = tmpLNAME;
	array[index + 1][JNUM] = tmpJNUM;
}

//************************************************
//Function to sort the array by last name
//************************************************
void sortArray(string array[ROWS][COLS])
{
	int endOfData = firstAvailableRow(array);

	for (int i = 0; i < endOfData -1; i++)
	{
		for (int j = 0; j < endOfData; j++)
		{
			if (array[j][LNAME] > array[j + 1][LNAME])
			{
				swapRecords(array, j);
			}
		}
	}
	Banner("Data Sorted by Last Name: " + to_string(endOfData) + " Records ");
}