#pragma once

#include "BST.h"
#include "person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



void runInput(std::string inputFileName, std::vector<Person> people);

void runInput(std::string inputFileName, std::vector<Person> people)
{
	int inDay, inMonth, inYear;
	char separator;
	std::string inName;
	std::ifstream myfile;
	myfile.open(inputFileName);
	while ()
	{
		myfile >> inDay;

		myfile >> separator;

		myfile >> inMonth;

		myfile >> separator;

		myfile >> inYear;

		myfile >> separator;

		std::getline(myfile, inName, '\n');

		// Ignore the newline, as it is still in the buffer.
		myfile.ignore(10000, '\n');

		// Process or store values.

	}
	myfile.close();
}