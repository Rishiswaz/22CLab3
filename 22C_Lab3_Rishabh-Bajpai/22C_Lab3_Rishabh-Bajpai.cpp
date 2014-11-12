// 22C_Lab3_Rishabh-Bajpai.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "person.h"
#include "BST.h"
#include "Implementation.h"
#include <vector>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	BST tree;
	std::vector <Person> vectorOfPeople;
	std::string filename;
	std::cout << "Please enter the file name and extension of your input file" << std::endl
		<< "Supported file formats: .csv and .txt; .txt files must have values seperated by commas" << std::endl;
	std::getline(std::cin, filename, '\n');
	runInput(filename, vectorOfPeople);
	buildTree(vectorOfPeople, tree);

	return 0;
}

