// main.cpp
// Evan Overman
// Created Oct 22, 2020

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sys/types.h>

std::vector <std::string> splitString(std::string text, char split) // Splits one string into many by dividing it whenever the char "split" appears
{
	std::vector <std::string> splitText; // Create a vector for the split strings
	size_t position = text.find(split); // Check if the text contains the char "split", if so will return std::string::npos
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

void printHelp(std::string argv = "./AutoWebServer")
{
	std::cout << "Usage: " << argv << " <option> <sub-option>" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "\t-h, --help\t\t\t\tShow this help message." << std::endl;
	std::cout << "\t-S, --setup [system, debian]\t\tRun setup." << std::endl;
	std::cout << "\t-o, --organized [port, 80]\t\tStart server using organized format." << std::endl;
	std::cout << "\t-s, --simple [port, 80]\t\t\tStart server using simple format." << std::endl;
	std::cout << "\t-p, --prompt\t\t\t\tUse the program with prompts instead of arguments." << std::endl;

	std::cout << std::endl;
	std::cout << "Sub-Options:" << std::endl;
	std::cout << "\t[system]\t\t\t\t(debian, deb, ubuntu)" << std::endl;
	std::cout << "\t[port]\t\t\t\t\tInteger, i.e. 80" << std::endl;
}

#include "dirent.h" // Include Dirent by tronkko: https://github.com/tronkko/dirent
#include "directoryIndexing.h"
#include "dirVects.h"
#include "serverJS.h"
#include "setup.h"

int main(int argc, char* argv[]) // note to self: argv[0] is ./a.out
{
	std::cout << dir::listDir(getcwd());
	if(argv[1] != nullptr)
	{
		if(std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") // Output help page to console.
		{
			printHelp(std::string(argv[0]));
		}
		else if(std::string(argv[1]) == "--setup" || std::string(argv[1]) == "-S") // Start the setup.
		{
			if(argv[2] != nullptr) // Check if the argument after argv[1] is empty, if not, use as more input.
			{
				if(std::string(argv[2]) == "debian" || std::string(argv[2]) == "deb" || std::string(argv[2]) == "ubuntu") // Check if the second arg is debian or its aliases.
				{
					setup::debianSetup(); // Run debian setup.
				}
			}
			else if(argv[2] == nullptr) // If no further input was given, use default.
			{
				setup::debianSetup(); // Run debian setup.
			}
			else // Something weird as fuck just happened.
			{
				std::cout << "An unknown error has occured. [ argv[2] was neither equal nor unequal to null ]." << std::endl;
			}
		}
		else if(std::string(argv[1]) == "--organized" || std::string(argv[1]) == "-o")
		{
			std::string port = "80";

			if(argv[2] != nullptr)
			{
				port = std::string(argv[2]);
			}

			dirIndexing::compounds::makeOrgDirIndex(); // create dirIndexies for the organized format.
			node::makeOrgServerJS("dirIndex", "pagesDirIndex", "picturesDirIndex", "cssDirIndex", "jsDirIndex", "downloadsDirIndex", port); // Make a server.js file.
			system("sudo node server.js");
		}
		else if(std::string(argv[1]) == "--simple" || std::string(argv[1]) == "-s")
		{
			std::string port = "80";

			if(argv[2] != nullptr)
			{
				port = std::string(argv[2]);
			}

			dirIndexing::compounds::makeSimpleDirIndex();
			node::makeServerJS("simpleDirIndex", port);
			system("sudo node server.js");
		}
		else if(std::string(argv[1]) == "--prompt" || std::string(argv[1]) == "-p")
		{
			std::string yn = "n";

			while (true)
			{
				std::cout << "Would you like to go though first time setup? [Y/n]: ";
				std::cin >> yn;

				if (yn == "y" || yn == "Y")
				{
					setup::debianSetup(); // Start setup for debian based systems (setup.h).
					break;
				}
				else if(yn == "n" || yn == "Y")
				{
					break;
				}
				else // No valid input was given.
				{
					std::cout << "Please give a valid input." << std::endl;
				}
			}

			while(true)
			{
				std::cout << "Directory formats:" << std::endl;
				std::cout << "\t[1] - Organized, uses multiple folders for file formats." << std::endl;
				std::cout << "\t[2] - Simple, uses one directory with no folders." << std::endl;
				std::cout << "Pick a format [1, 2]: ";

				std::string dirFormat;
				std::cin >> dirFormat;

				if(dirFormat == "1")
				{
					dirIndexing::compounds::makeOrgDirIndex(); // create dirIndexies for the organized format.
					std::string port;
					std::cout << "Port? [int]: "; // get port to host server on from the user.
					std::cin >> port;

					node::makeOrgServerJS("dirIndex", "pagesDirIndex", "picturesDirIndex", "cssDirIndex", "jsDirIndex", "downloadsDirIndex", port);
					std::cout << "Would you like to start the server? (You may be prompted for your password.) [Y/n]: ";
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

						dirIndexing::compounds::makeSimpleDirIndex(); // Make a simple, single directory, index.
						node::makeServerJS("simpleDirIndex.ls", port); // Make/write to the server.js file.

						std::cout << "Would you like to start the server? (You may be prompted for your password.) [Y/n]: ";
						std::cin >> yn;

						if(yn == "y" || yn == "Y") 
						{
							system("sudo node server.js"); // Start the server.js file.
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
		else
		{
			printHelp(std::string(argv[0]));
		}
	}
	else if(argv[1] == nullptr)
	{
		printHelp(std::string(argv[0]));
	}
	else
	{
		std::cout << "An unknown error has occured. [ argv[1] was neither equal nor unequal to null ]." << std::endl;
	}

	return 0;
}
