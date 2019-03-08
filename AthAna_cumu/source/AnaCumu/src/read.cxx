#include <iostream>
#include <fstream>

void read()
{
	ifstream inFile;
	inFile.open("cent_86.txt");
	string x;
	double y;
	while(!inFile.eof())
	{
		inFile >> x >> y;
		cout<<y<<", ";
	}
}

