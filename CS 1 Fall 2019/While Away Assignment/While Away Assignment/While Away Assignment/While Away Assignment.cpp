// While Away Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	int GT = 20;
	double HighwayMPG = 28.9;
	double TownMPG = 23.5;

	int D1 = GT * HighwayMPG;
	int D2 = GT * TownMPG;

	string GallonsPerTank;
	GallonsPerTank = "GT";
	string ACMPG;
	ACMPG = "Average City Miles per Gallon";
	string MDIC;
	MDIC = "Max Distance in City";
	string AHMPG;
	AHMPG = "Average Highway Miles per Gallon";
	string MDOH;
	MDOH = "Max Distance on Highway";
	

	


	cout << "Gallons per Tank" << "=" << GT << endl;
	cout << endl;
	cout << ACMPG << "=" << TownMPG << endl;
	cout << MDIC << "=" << D2 << endl;
	cout << endl;
	cout << AHMPG << "=" << HighwayMPG << endl;
	cout << MDOH << "=" << D1 << endl; 
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
