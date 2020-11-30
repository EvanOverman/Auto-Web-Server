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

    else
    {
        if (std::string(argv[1]) == "--non-iterative" || std::string(argv[1]) == "-n")
        {
			if (argv[2] == NULL || std::string(argv[2]) == "help")
			{
                usage::nonIterative(argv[0]);
                return 0;
			}
            
            else
            {
                if (std::filesystem::is_directory(std::string(argv[2])))
                {
                    std::vector <std::filesystem::path> files; // Vector for file paths.
                    std::filesystem::path dir = std::string(argv[2]);

                    for (auto& path: std::filesystem::directory_iterator(dir))
                    {
                        if (!path.is_directory())
                        {
                            files.push_back(path); // Add file paths to files.
                        }

                    }

                    express::node serverjs;
                    serverjs.makeFile("server.js");
                    serverjs.import("express");
                    serverjs.import("path");

                    if (argv[3] != NULL)
                    {
                        if (argv[4] != NULL && std::find(files.begin(), files.end(), std::string(argv[4])) != files.end()) // Check if argv[4] is not NULL, then see if the file exists.
                        {
                            serverjs.redirect("/", std::string(argv[3])); // Add a redirect from "/" to the given home page.
                        }

                        else if (argv[4] != NULL && std::find(files.begin(), files.end(), std::string(argv[4])) == files.end())
                        {
                            usage::homeFileDoesNotExist();
                            return 1;
                        }

                        else if (std::find(files.begin(), files.end(), "index.html") != files.end()) // Default to redirecting "/" to "index.html".
                        {
                            serverjs.redirect("/", "index.html");
                        }

                    }

                    for (int count = 0; count < files.size(); count++) // Loop though elements of vector "files".
                    {
                        serverjs.get(files[count].string()); // Add get statements to the server.js file.
                    }
                    
                    serverjs.listen(std::string(argv[3])); // Add a listen function to the file.

                }

                else
                {
                    usage::nonIterative(argv[0]);
                    return 1;
                }
                
            }
            
        }

    }
    
}