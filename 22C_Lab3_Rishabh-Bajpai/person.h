#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Birthday
{
public:
	Birthday();
	~Birthday();
	Birthday(const Birthday& rhs);
	friend std::ostream& Birthday::operator << (std::ostream& output, const Birthday& rhs)
	{
	output<< rhs.day<< " " << rhs.month<< " " << rhs.year;
	return output;
	}

	bool Birthday::operator == (const Birthday& rhs)
	{
		bool finalcheck= false, dayCheck=false, monthCheck=false, yearCheck=false;

		if (day == rhs.day)
		{
			dayCheck = true;
		};
		if (month == rhs.month)
		{
			monthCheck = true;
		};
		if (year == rhs.year)
		{
			yearCheck = true;
		}
		if (dayCheck == true && monthCheck == true && yearCheck == true)
		{
			finalcheck= true;
		}
		return finalcheck;
	}

	int sumOfBirthdate();
	void input(int, int, int);
private:
	int day, month, year;
	
};

Birthday::Birthday()
{
}

Birthday::Birthday(const Birthday& rhs)
{
	day = rhs.day;
	month = rhs.month;
	year = rhs.year;
}

Birthday::~Birthday()
{
}


class Person
{
public:
	Person();
	~Person();
	void insertValues(Birthday bdayIn, std::string nameIn);
	void output_PO();
	void output_BF();
	
	int key;

	bool Person::operator <  (      Person& rhs);
	bool Person::operator != (const Person& rhs);
	bool Person::operator >  (		Person& rhs);
	friend std::ostream& Person::operator << (std::ostream& output, const Person& rhs)
	{
		output << rhs.dOB<<" "<<rhs.name;
		return output;
	}

protected:
	Birthday dOB; //date of birth
	std::string name; //name of individual
	
};

Person::Person()
{

}

Person::~Person()
{
}

void Person::insertValues(Birthday bdayIn, std::string nameIn)
{
	dOB = bdayIn;
	name = nameIn;
}

int Birthday::sumOfBirthdate()
{

	int sum = day+month+year;
	return sum;

}

void Birthday::input(int inDay, int inMonth, int inYear)
{
	day = inDay;
	month = inMonth;
	year = inYear;
}

bool Person::operator < (Person& rhs)
{
	
	if (rhs.dOB.sumOfBirthdate()>dOB.sumOfBirthdate())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Person::operator > (Person& rhs)
{

	if (rhs.dOB.sumOfBirthdate()<dOB.sumOfBirthdate())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Person::operator != (const Person& rhs)
{
	bool finalCheck= true, birthdayCheck=true, nameCheck=true;
	
	if (name == rhs.name)
		nameCheck = true;
	if (dOB == rhs.dOB)
		birthdayCheck = true;
	if (nameCheck == true && birthdayCheck == true)
		finalCheck = false;
	return finalCheck;
}
