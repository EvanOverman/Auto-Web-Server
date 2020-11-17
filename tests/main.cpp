// main.cpp *TEST*
// Evan Overman
// Made November 1, 2020
// Last update: November 1, 2020

#include <iostream>
#include <string>

#include "directories.hpp"

using namespace std;

int main() 
{
	string path;
	vector <string> files;
	cout << "path: ";
	cin >> path;
	read_directory(path, files);
	return 0;
}