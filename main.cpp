// main.cpp
// Evan Overman
// Created Oct 22, 2020
// Last update: Oct 22, 2020

#include <string>
#include <vector>
#include <iostream>

#include "directoryIndexing.h"
#include "serverJS.h"

using namespace std;

int main() {
	makeDirIndex();

	string port;
	cout << "Port? [3000]: ";
	cin >> port;

	makeServerJS("dirIndex.ls", port);
}

