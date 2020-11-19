// main.cpp
// Evan Overman
// Created Oct 22, 2020
// Last update: Nov 19, 2020

#include <string>
#include <vector>
#include <iostream>

#include "directoryIndexing.h"
#include "serverJS.h"
#include "setup.h"

using namespace std;

int main() 
{
	string yn = "n";

	while(true) 
	{
		cout << "Pick a directory format:" << endl;
		cout << "\t[1] - Organized, uses multiple folders for file formats." << endl;
		cout << "\t[2] - Simple, uses one directory with no folders." << endl;
		cout << "Pick a format [1, 2]: ";

		string dirFormat;
		cin >> dirFormat;

		if(dirFormat == "1") 
		{
			makeOrgDirIndex(); // create dirIndexies for the organized format
			string port;
			cout << "Port? [int]: "; // get port to host on from user
			cin >> port;

			makeOrgServerJS("dirIndex", "pagesDirIndex", "picturesDirIndex", "cssDirIndex", "jsDirIndex", "downloadsDirIndex", port);
			cout << "Would you like to start the server? [Y/n]: ";
			cin >> yn;

			if(yn == "y" || yn == "Y") 
			{
				system("sudo node server.js"); // Start the server.js file
				break;
			} 
			else if(yn == "n" || yn == "N")
			{
				break;
			}
			else
			{
				cout << "Please give a valid input." << endl;
			}
		} 
		else if (dirFormat == "2") 
		{
			cout << "Are you sure you want to use the simple format? This format does not support downloads without manualy editing the server.js file. [y/N]: ";
			cin >> yn;

			if(yn == "y" || yn == "Y") 
			{
				string port;
				cout << "Port? [int]: ";
				cin >> port;

				makeServerJS("simpleDirIndex.ls", port); // Make/write to the server.js file

				cout << "Would you like to start the server? [Y/n]: ";
				cin >> yn;

				if(yn == "y" || yn == "Y") 
				{
					system("node server.js"); // Start the server.js file
					break;
				} 
				else if(yn == "n" || yn == "N")
				{
					break;
				}
				else
				{
					cout << "Please give a valid input." << endl;	
				}
			}
		} 
		else 
		{
			cout << "Please give a valid input." << endl;
		}
	}	
}