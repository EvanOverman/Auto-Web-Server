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
			for (std::string arg: usage::args)
			{
				if (arg == std::string(argv[count + 1]))
				{
					std::cerr << errors.no_value_given(std::string(argv[count]));
					return 1;
				}

			}

			if (!std::filesystem::is_directory(std::string(argv[count + 1])))
			{
				std::cerr << errors.directory_does_not_exist(server.dir);
				return 1;
			}
			
			server.recursive = false;
			server.dir = std::filesystem::path(std::string(argv[count + 1]));
			count++;
			
		}

		else if (std::string(argv[count]) == "/recursive" || std::string(argv[count]) == "/r")
		{
			for (std::string arg: usage::args)
			{
				if (arg == std::string(argv[count + 1]))
				{
					std::cerr << errors.no_value_given(std::string(argv[count]));
					return 1;
				}

			}

			if (!std::filesystem::is_directory(std::string(argv[count + 1])))
			{
				std::cerr << errors.directory_does_not_exist(server.dir);
				return 1;
			}
			
			server.recursive = true;
			server.dir = std::filesystem::path(std::string(argv[count + 1]));
			count++;

		}
		
		else if (std::string(argv[count]) == "/port" || std::string(argv[count]) == "/p")
		{
			for (std::string arg: usage::args)
			{
				if (arg == std::string(argv[count + 1]))
				{
					std::cerr << errors.no_value_given(std::string(argv[count]));
					return 1;
				}

			}

			if (std::string(argv[count + 1]).find_first_not_of("0123456789") == std::string::npos)
			{
				server.port = int(argv[count + 1]);
			}

			else
			{
				std::cerr << errors.invalid_port(std::string(argv[count + 1]));
				return 1;
			}

			count++;

		}

		else if (std::string(argv[count]) == "/file" || std::string(argv[count]) == "/f")
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
			}

			else
			{
				std::cerr << errors.invalid_file_name(std::string(argv[count + 1]));
				return 1;
			}

			count++;
			
		}

		else if (std::string(argv[count]) == "/downloads" || std::string(argv[count]) == "/d")
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
			}

			else if (std::string(argv[count + 1]) == "false" || std::string(argv[count + 1]) == "0")
			{
				server.downloads = false;
			}

			else
			{
				errors.non_bool_given(std::string(argv[count + 1]));
				return 1;
			}

			count++;

		}

		js_file.open(server.file);
		js_file.clear();
		js_file.import("path");
		js_file.import("express");

	}

}