#pragma once

#include <iostream>
#include <string>
#include <fstream>

struct Birthday
{
	//structure for holding the values for a person's birthday
	int day, month, year;
};

class Person
{
public:
	Person();
	~Person();
	void insertValues(Birthday bdayIn, std::string nameIn);
	void output_PO();
	void output_BF();
	int key;
private:
	Birthday dOB; //date of birth
	std::string name; //name of individual
	
};

Person::Person()
{

}

Person::~Person()
{
}

void Person::output_PO()
{
	std::ofstream myfile;
	myfile.open("post-order_output.txt");
	myfile << name << " " << dOB.day << " " << dOB.month << " " << dOB.year;
	myfile.close();
}
void Person::output_BF()
{
	std::ofstream myfile;
	myfile.open("breadth-first_output.txt");
	myfile << name << " " << dOB.day << " " << dOB.month << " " << dOB.year;
	myfile.close();
}

void Person::insertValues(Birthday bdayIn, std::string nameIn)
{
	dOB = bdayIn;
	name = nameIn;
}