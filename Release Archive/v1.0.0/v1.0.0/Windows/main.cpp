/*

Evan Overman
main.cpp
Created 11/28/2020

Compile: cl /std:c++17 /EHsc main.cpp

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
	node::paths::js_file js_file_paths;
	usage::errors errors;
	usage::help help;

	server.downloads = false;
	server.recursive = false;
	server.port = 80;
	server.downloads_folder = "DOWNLOADS";
	server.index = "index.html";
	server.file = "server.js";
	server.dir = "./";

	for (int count = 0; count < argc; count++)
	{
		if (std::string(argv[count]) == "/help" || std::string(argv[count]) == "/h")
		{
			std::cout << help.man(argv);
			return 0;
		}

		else if (std::string(argv[count]) == "/directory" || std::string(argv[count]) == "/D")
		{
			if (argv[count + 1] != NULL)
			{
				if (std::filesystem::is_directory(std::string(argv[count + 1])))
				{
					server.dir = std::string(argv[count + 1]);
					count++;
				}

				else 
				{
					std::cerr << errors.directory_does_not_exist(std::string(argv[count + 1]));
					return 1;
				}
			}
			
			else
			{
				std::cerr << errors.no_value_given(std::string(argv[count]));
				return 1;
			}
			
		}

		else if (std::string(argv[count]) == "/recursive" || std::string(argv[count]) == "/r")
		{
			if (argv[count + 1] != NULL)
			{
				if (std::string(argv[count + 1]) == "true" || std::string(argv[count + 1]) == "1")
				{
					server.recursive = true;
					count++;
				}

				else if (std::string(argv[count + 1]) == "false" || std::string(argv[count + 1]) == "0")
				{
					server.recursive = false;
					count++;
				}

			}
			
			else
			{
				server.recursive = true;
			}

		}
		
		else if (std::string(argv[count]) == "/port" || std::string(argv[count]) == "/p")
		{
			if (argv[count + 1] != NULL)
			{
				for (std::string arg: usage::args)
				{
					if (arg == std::string(argv[count + 1]))
					{
						std::cerr << errors.no_value_given(std::string(argv[count]));
						return 1;
					}

				}

				bool is_number = true;

				for (char letter: std::string(argv[count + 1]))
				{
					if (letter != '0' && 
						letter != '1' && 
						letter != '2' && 
						letter != '3' && 
						letter != '4' && 
						letter != '5' && 
						letter != '6' && 
						letter != '7' && 
						letter != '8' && 
						letter != '9')
					{
						is_number = false;
					}
				}

				if (is_number)
				{
					server.port = atoi(argv[count + 1]);
					count++;
				}

				else
				{
					std::cerr << errors.invalid_port(std::string(argv[count + 1]));
					return 1;
				}

			}
			
			else
			{
				std::cerr << errors.no_value_given(std::string(argv[count]));
				return 1;
			}
			
		}

		else if (std::string(argv[count]) == "/file" || std::string(argv[count]) == "/f")
		{
			if (argv[count + 1] != NULL)
			{
				for (std::string arg: usage::args)
				{
					if (arg == std::string(argv[count + 1]))
					{
						std::cerr << errors.no_value_given(std::string(argv[count]));
						return 1;
					}

				}

				if (std::string(argv[count + 1]).find_first_of("/") == std::string::npos)
				{
					server.file = std::string(argv[count + 1]);
					count++;
				}

				else
				{
					std::cerr << errors.invalid_file_name(std::string(argv[count + 1]));
					return 1;
				}
			}
			
			else
			{
				std::cerr << errors.no_value_given(std::string(argv[count]));
				return 1;
			}
			
		}

		else if (std::string(argv[count]) == "/index" || std::string(argv[count]) == "/i")
		{
			if (argv[count + 1] != NULL)
			{
				for (std::string arg: usage::args)
				{
					if (arg == std::string(argv[count + 1]))
					{
						std::cerr << errors.no_value_given(std::string(argv[count]));
						return 1;
					}

				}

				server.index = std::string(argv[count + 1]);
				count++;
			}
			
			else
			{
				std::cerr << errors.no_value_given(std::string(argv[count]));
				return 1;
			}
			
		}

		else if (std::string(argv[count]) == "/downloads" || std::string(argv[count]) == "/d")
		{
			if (argv[count + 1] != NULL)
			{
				for (std::string arg: usage::args)
				{
					if (arg == std::string(argv[count + 1]))
					{
						std::cerr << errors.no_value_given(std::string(argv[count]));
						return 1;
					}

				}

				if (std::string(argv[count + 1]) == "true" || std::string(argv[count + 1]) == "1")
				{
					server.downloads = true;
					count++;
				}

				else if (std::string(argv[count + 1]) == "false" || std::string(argv[count + 1]) == "0")
				{
					server.downloads = false;
					count++;
				}

				else
				{
					if (std::filesystem::is_directory(std::string(argv[count + 1])))
					{
						server.downloads_folder = std::string(argv[count + 1]);
						server.downloads = true;
					}

					else
					{
						std::cerr << errors.directory_does_not_exist(std::string(argv[count + 1]));
						return 1;
					}
									
				}

			}
			
			else
			{
				std::cerr << errors.no_value_given(std::string(argv[count]));
				return 1;
			}
			
		}

	}

	js_file_paths.clear(server.file);
	js_file_paths.open(server.file);
	js_file_paths.import("path");
	js_file_paths.import("express");

	std::vector <std::filesystem::path> files;

	if (server.recursive)
	{
		files = files::paths::recursive(server.dir);
	}

	else
	{
		files = files::paths::non_recursive(server.dir);
	}
		
	for (std::filesystem::path file: files)
	{
		if (file.string().find(server.index) != std::string::npos)
		{
			js_file.redirect("/" + server.index, "/");
		}

	}

	for (std::filesystem::path file: files)
	{
		if (file.string().find(server.downloads_folder) != std::string::npos && server.downloads == true)
		{
			js_file_paths.download(file);
		}

		else
		{
			js_file_paths.get(file);
		}
	
	}

	js_file_paths.listen(server.port);
	return 0;

}