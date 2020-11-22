// main.cpp
// Evan Overman
// Created Oct 22, 2020
// Last update: Nov 21, 2020

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> splitString(std::string text, char split) // Splits one string into many by dividing it whenever the char "split" appears
{ 
    std::vector <std::string> splitText; // Create a vector for the split strings
    size_t position = text.find(split); // Check if the text contains the char "split", if so will return string::npos
    size_t initialPosition = 0;

    while(position != std::string::npos) // if the text contains the char "split", split it by the char "split"
	{ 
        splitText.push_back(text.substr(initialPosition, position - initialPosition));
        initialPosition = position + 1;
        position = text.find(split, initialPosition);
    }

    splitText.push_back(text.substr(initialPosition, std::min(position, text.size()) - initialPosition + 1));
    return splitText;
}

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
			setup::debianSetup(); // Start setup (setup.h).
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