// In Class Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	float starting_number_of_organisms,
		avarage_daily_population_increase,
		size_of_daily_population;

	int number_of_days_to_multiply;



	cout << "Enter the starting number of organisms: ";
	
	while (!(cin >> starting_number_of_organisms) || starting_number_of_organisms < 2)
	{				
		cout << "Error. Starting number must be 2 or greater than\n" << endl;
		cout << "Enter the starting number of organisms";
		cin >> starting_number_of_organisms;
	}



	cout << "Enter the average daily population increase (as a percentage): ";
	
	while (!(cin >> avarage_daily_population_increase) || avarage_daily_population_increase < 0)
	{
		cout << "Error. Average daily population increase must be greater than 0" << endl;
		cout << "Enter the average daily population increase: ";
		cin >> avarage_daily_population_increase;
	}


	avarage_daily_population_increase *= .01;

	cout << "Enter the amount of days they will multiply: ";

	while (!(cin >> number_of_days_to_multiply) || number_of_days_to_multiply < 1)
	{
		cout << "Error. Number of days must NOT be less than 1" << endl;
		cout << "Enter the number of days they will multiply: "; 
		cin >> number_of_days_to_multiply;
	}
	


	for (int i = 0; i < number_of_days_to_multiply; i++)
	{
		cout << "Population size for day " << (i + 1);
		cout << ": " << starting_number_of_organisms << endl;


		starting_number_of_organisms += (starting_number_of_organisms * avarage_daily_population_increase);
	}

	return 0;

}