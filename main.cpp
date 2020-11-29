/*

Evan Overman
main.cpp
Created 11/28/2020

*/

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

void usage (std::string executable = "./AutoWebServer")
{
	std::cout << "Usage: " << executable << " <option> <sub-option>" << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "\t-h, --help\t\t\t\tShow this help message." << std::endl;
	std::cout << "\t-S, --setup [system, debian]\t\tRun setup." << std::endl;
	std::cout << "\t-o, --organized [port, int]\t\tStart server using organized format." << std::endl;
	std::cout << "\t-s, --simple [port, int]\t\t\tStart server using simple format." << std::endl;
	std::cout << "\t-p, --prompt\t\t\t\tUse the program with prompts instead of arguments." << std::endl;

	std::cout << std::endl;
	std::cout << "Sub-Options:" << std::endl;
	std::cout << "\t[system]\t\t\t\t(debian, deb, ubuntu)" << std::endl;
	std::cout << "\t[port]\t\t\t\t\tInteger, i.e. 80" << std::endl;
}

#include "express.hpp"
#include "serverjs.hpp"

int main (int argc, char *argv[])
{  
    if (argv[1] == NULL) // No arguments given, output usage to user.
    {
        usage(argv[0]);
    }

    else
    {
        if (std::string(argv[1]) == "--simple" || std::string(argv[1]) == "-s")
        {
			
        }

    }
    
}