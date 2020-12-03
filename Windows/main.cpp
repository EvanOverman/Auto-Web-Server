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
#include "node.hpp"
#include "usage.hpp"
#include "files.hpp"

int main (int argc, char *argv[])
{  
	node::server server;
	node::js_file js_file;
	usage::errors errors;
	usage::help help;

	for (int count = 0; count < argc; count++)
	{
		if (std::string(argv[count]) == "/help" || std::string(argv[count]) == "/h")
		{
			std::cout << help.man(argv);
			return 0;
		}

		else if (std::string(argv[count]) == "/non-recursive" || std::string(argv[count]) == "/n")
		{
			if (std::string(argv[count + 1]) != )
			{

			}
			server.recursive = false;
			server.dir = std::filesystem::path(std::string(argv[count+1]));

			if (!std::filesystem::is_directory(std::string(argv[count + 1])))
			{
				std::cerr << errors.directory_does_not_exist(server.dir);
				return 1;
			}
			
		}

		else if (std::string(argv[count]) == "/recursive" || std::string(argv[count]) == "/r")
		{
			server.recursive = true;
		}
		
		else if (std::string(argv[count]) == "/port" || std::string(argv[count]) == "/p")
		{
			server.port = int(argv[count + 1]);
		}

		else if (std::string(argv[count]) == "/file" || std::string(argv[count]) == "/f")
		{
			if (!std::string(argv[count + 1])[0] == '/')
			{
				server.file = std::string(argv[count + 1]);
			}

			else
			{
				std::cerr << errors.invalid_file_name(std::string(argv[count + 1]));
				return 1;
			}
			
		}

		else if (std::string(argv[count]) == "/downloads" || std::string(argv[count]) == "/d")
		{
			if (std::string(argv[count + 1]) == "true" || std::string(argv[count + 1]) == "1")
			{
				server.downloads = true;
			}

		}

	}



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
			std::filesystem::path dir = std::string(argv[2]);
			std::vector <std::string> files = files::non_recursive(dir); // Vector for file paths.

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
			std::filesystem::path dir = std::string(argv[2]);
			std::vector <std::string> files = files::recursive(dir); // Vector for file paths.

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
				if (files[count].find("DOWNLOADS/") != std::string::npos) // Check if path contains the directory "DOWNLOADS".
				{
					serverjs.download(files[count]); // Add download statement to the server.js file.
				}

				else
				{
					serverjs.get(files[count]); // Add get statements to the server.js file.
				}

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