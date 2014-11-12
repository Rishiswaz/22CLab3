#pragma once

#include "BST.h"
#include "person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void runInput(std::string inputFileName, std::vector<Person>& people);
void buildTree(std::vector<Person> people, BST& tree);


void runInput(std::string inputFileName, std::vector<Person>& people)
{
	int inDay, inMonth, inYear,i=0;
	Birthday inBday;
	char separator;
	std::string inName;
	std::ifstream myfile;
	myfile.open(inputFileName);
	while (myfile.good())
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
		inBday.day = inDay;
		inBday.month = inMonth;
		inBday.year = inYear;
		// Process or store values.
		people[i].insertValues(inBday, inName);
		i += 1;
	}
	myfile.close();
}

void buildTree(std::vector<Person> people, BST& tree)
{
	int j = people.size();
	if (j == 0)
	{
		std::cout << "Your list of people is empty" << std::endl
			<< "Was your input file formatted correctly?" << std::endl
			<< "Check to make sure it is in 'DD,MM,YYYY' format" << std::endl;
	}
	for (int i = 0; i < j; i++)
	{
		tree.insert(people[i]);
	}
}