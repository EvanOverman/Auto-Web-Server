// main.cpp
// Evan Overman
// Created Oct 22, 2020
// Last update: Nov 21, 2020

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "directoryIndexing.h"
#include "serverJS.h"
#include "setup.h"

int main() 
{
	std::string yn = "n";

	while (true)
	{
		std::cout << "Would you like to go though first time setup? [Y/n]: ";
		std::cin >> yn;

		if (yn == "y" || yn == "Y")		
		{
			setup(); // Start setup (setup.h).
			break;
		}
		else if(yn == "n" || yn == "Y")
		{
			break;
		}
		else
		{
			std::cout << "Please give a valid input." << std::endl;
		}
	}

	while(true) 
	{
		std::cout << "Pick a directory format:" << std::endl;
		std::cout << "\t[1] - Organized, uses multiple folders for file formats." << std::endl;
		std::cout << "\t[2] - Simple, uses one directory with no folders." << std::endl;
		std::cout << "Pick a format [1, 2]: ";

		std::string dirFormat;
		std::cin >> dirFormat;

		if(dirFormat == "1") 
		{
			dirIndexing::makeOrgDirIndex(); // create dirIndexies for the organized format
			std::string port;
			std::cout << "Port? [int]: "; // get port to host on from user
			std::cin >> port;

			node::makeOrgServerJS("dirIndex", "pagesDirIndex", "picturesDirIndex", "cssDirIndex", "jsDirIndex", "downloadsDirIndex", port);
			std::cout << "Would you like to start the server? [Y/n]: ";
			std::cin >> yn;

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
				std::cout << "Please give a valid input." << std::endl;
			}
		} 
		else if (dirFormat == "2") 
		{
			std::cout << "Are you sure you want to use the simple format? This format does not support downloads without manualy editing the server.js file. [y/N]: ";
			std::cin >> yn;

			if(yn == "y" || yn == "Y") 
			{
				std::string port;
				std::cout << "Port? [int]: ";
				std::cin >> port;

				dirIndexing::makeSimpleDirIndex(); // Make a simple, single directory, index.
				node::makeServerJS("simpleDirIndex.ls", port); // Make/write to the server.js file.

				std::cout << "Would you like to start the server? [Y/n]: ";
				std::cin >> yn;

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
					std::cout << "Please give a valid input." << std::endl;	
				}
			}
		} 
		else 
		{
			std::cout << "Please give a valid input." << std::endl;
		}
	}	
}