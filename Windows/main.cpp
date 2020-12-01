/*

Evan Overman
main.cpp
Created 11/28/2020

*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>

#include "express.hpp"
#include "usage.hpp"

int main (int argc, char *argv[])
{  
	if (argv[1] == NULL) // No arguments given, output usage to user.
	{
		usage::usage(argv[0]);
		return 0;
	}

	else if (std::string(argv[1]) == "/help" || std::string(argv[1]) == "/h")
	{
		usage::usage(argv[0]);
		return 0;
	}

	else if (std::string(argv[1]) == "/non-iterative" || std::string(argv[1]) == "/n")
	{
		if (argv[2] == NULL || std::string(argv[2]) == "help")
		{
			usage::nonIterative(argv[0]);
			return 0;
		}

		else if (std::filesystem::is_directory(std::string(argv[2])))
		{
			std::vector <std::string> files; // Vector for file paths.
			std::filesystem::path dir = std::string(argv[2]);

			for (std::filesystem::path path: std::filesystem::directory_iterator(dir))
			{
				if (!std::filesystem::is_directory(path)) // Filter out any non-file results.
				{
					std::string _path = path.relative_path().string();

					if (_path[0] == '.')
					{
						_path.erase(0, 1);
					}

					std::replace(_path.begin(), _path.end(), '\\', '/');
					files.push_back(_path); // Add file paths to files.
				}

			}

			express::node serverjs;
			serverjs.clear();
			serverjs.open("server.js");
			serverjs.import("express");
			serverjs.import("path");

			if (argv[3] != NULL)
			{
				if (argv[4] != NULL) // Check if argv[4] is not NULL, then see if the file exists.
				{
					if (std::find(files.begin(), files.end(), std::string(argv[4])) != files.end())
					{
						serverjs.redirect("/", std::string(argv[3])); // Add a redirect from "/" to the given home page.
					}
						
					else if (std::find(files.begin(), files.end(), std::string(argv[4])) == files.end())
					{
						usage::homeFileDoesNotExist();
						return 1;
					}
					
				}

				else if (std::find(files.begin(), files.end(), "index.html") != files.end()) // Default to redirecting "/" to "index.html".
				{
					serverjs.redirect("/", "index.html");
				}
			}

			for (int count = 0; count < files.size(); count++) // Loop though elements of vector "files".
			{
				serverjs.get(files[count]); // Add get statements to the server.js file.
			}
				
			if (argv[3] != NULL)
			{
				serverjs.listen(std::string(argv[3])); // Add a listen function to the file.
			}
				
			else
			{
				serverjs.listen("80");
			}
		}

		else
		{
			usage::nonIterative(argv[0]);
			return 1;
		}
	
	}

	else if (std::string(argv[1]) == "/iterative" || std::string(argv[1]) == "/i")
	{
		if (argv[2] == NULL || std::string(argv[2]) == "help")
		{
			usage::iterative(argv[0]);
			return 0;
		}

		else if (std::filesystem::is_directory(std::string(argv[2])))
		{
			std::vector <std::string> files; // Vector for file paths.
			std::filesystem::path dir = std::string(argv[2]);

			for (std::filesystem::path path: std::filesystem::recursive_directory_iterator(dir))
			{
				if (!std::filesystem::is_directory(path)) // Filter out any non-file results.
				{
					std::string _path = path.relative_path().string();

					if (_path[0] == '.')
					{
						_path.erase(0, 1);
					}

					std::replace(_path.begin(), _path.end(), '\\', '/');
					files.push_back(_path); // Add file paths to files.
				}

			}

			express::node serverjs;
			serverjs.clear();
			serverjs.open("server.js");
			serverjs.import("express");
			serverjs.import("path");
			
			if (argv[3] != NULL)
			{
				if (argv[4] != NULL) // Check if argv[4] is not NULL, then see if the file exists.
				{
					if (std::find(files.begin(), files.end(), std::string(argv[4])) != files.end())
					{
						serverjs.redirect("/", std::string(argv[3])); // Add a redirect from "/" to the given home page.
					}
						
					else if (std::find(files.begin(), files.end(), std::string(argv[4])) == files.end())
					{
						usage::homeFileDoesNotExist();
						return 1;
					}
					
				}

				else if (std::find(files.begin(), files.end(), "index.html") != files.end()) // Default to redirecting "/" to "index.html".
				{
					serverjs.redirect("/", "index.html");
				}
			}

			for (int count = 0; count < files.size(); count++) // Loop though elements of vector "files".
			{
				serverjs.get(files[count]); // Add get statements to the server.js file.
			}
				
			if (argv[3] != NULL)
			{
				serverjs.listen(std::string(argv[3])); // Add a listen function to the file.
			}
				
			else
			{
				serverjs.listen("80");
			}
		}

		else
		{
			usage::nonIterative(argv[0]);
			return 1;
		}
	
	}

}