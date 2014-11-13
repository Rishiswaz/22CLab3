#include "stdafx.h"
#include "person.h"
#include "BST.h"
#include "Implementation.h"
#include <vector>
#include <string>
#include <iostream>
int _tmain(int argc, _TCHAR* argv[])
{
	BST tree;
	std::vector <Person> vectorOfPeople;
	std::string filename = getFileName();
	runInput(filename, vectorOfPeople);
	system("CLS");
	buildTree(vectorOfPeople, tree);
	output(vectorOfPeople, tree);
	system("PAUSE");
	return 0;
}