#pragma once

#include "BST.h"
#include "person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void runInput(std::string inputFileName, std::vector<Person>& people);
void buildTree(std::vector<Person> people, BST& tree);
void output(std::vector<Person> people);
std::string getFileName();


void runInput(std::string inputFileName, std::vector<Person>& people)
{
	int inDay, inMonth, inYear,i=0;
	Birthday inBday;
	Person dummy;
	char separator;
	std::string inName;
	std::ifstream myfile;
	myfile.open(inputFileName);
	while (!myfile.eof())
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
		inBday.input(inDay,inMonth,inYear);
		// Process or store values.
		dummy.insertValues(inBday, inName);
		people.push_back(dummy);
		people[i].key = i+1;
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

void output(std::vector<Person> people)
{
	std::cout << "Printing tree sorted by name to: post-order_output.txt" << std::endl;
	for (int i = 0; i < people.size(); i++)
	{
		people[i].output_PO();
	}
	std::cout << "Printing tree sorted by date of birth to: breadth-first_output.txt" << std::endl;
	for (int i = 0; i < people.size(); i++)
	{
		people[i].output_BF();
	}
}

std::string getFileName()
{
	std::string filename;
	std::cout << "Please enter the file name and extension of your input file" << std::endl
		<< "Supported file formats: .csv and .txt; .txt files must have values seperated by commas" << std::endl;
	std::getline(std::cin, filename, '\n');
	return filename;
}