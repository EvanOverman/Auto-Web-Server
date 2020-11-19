// setup.h
// Evan Overman
// Created Nov 19, 2020
// Last update: Nov 19, 2020

#include <iostream>

void setup(void) // Run setup commands, in the future the setup funtion may be made to also support arch based systems.
{
    std::cout << "Sarting setup ..." << std::endl;

    std::cout << "Making directory 'simple' ..." << std::endl;
    std::system("mkdir simple");
    std::cout << "Making directory 'organized' ..." << std::endl;
    std::system("mkdir organized");
    std::cout << "Making directory 'organized/pages' ..." << std::endl;
    std::system("mkdir organized/pages");
    std::cout << "Making directory 'organized/css' ..." << std::endl;
    std::system("mkdir organized/css");
    std::cout << "Making directory 'organized/js' ..." << std::endl;
    std::system("mkdir organized/js");
    std::cout << "Making directory 'organized/pictures' ..." << std::endl;
    std::system("mkdir organized/pictures");
    std::cout << "Making directory 'organized/downloads' ..." << std::endl;
    std::system("mkdir organized/downloads");

    std::cout << "Making and populating 'dirIndex' ..." << std::endl;
    std::system("ls organized > dirIndex");
    std::cout << "Making and populating 'simpleDirIndex' ..." << std::endl;
    std::system("ls simple > simpleDirIndex");
    std::cout << "Making and populating 'pagesDirIndex' ..." << std::endl;
    std::system("ls organized/pages > pagesDirIndex");
    std::cout << "Making and populating 'cssDirIndex' ..." << std::endl;
    std::system("ls organized/css > cssDirIndex");
    std::cout << "Making and populating 'jsDirIndex' ..." << std::endl;
    std::system("ls organized/js > jsDirIndex");
    std::cout << "Making and populating 'picturesDirIndex' ..." << std::endl;
    std::system("ls organized/pictures > picturesDirIndex");
    std::cout << "Making and populating 'downloadsDirIndex' ..." << std::endl;
    std::system("ls organized/downloads > downloadsDirIndex");

    std::cout << "Making 'server.js' ..." << std::endl;
    std::system("echo 'No content yet, run Auto-Web-Server to populate this file.' > server.js");

    std::cout << "Updating reposity list, you may be prompted for your password ..." << std::endl;
    std::system("sudo apt -qq -y update");
    std::cout << "Installing Node.js ..." << std::endl;
    std::system("sudo apt -qq -y install nodejs");
    std::cout << "Installing npm ..." << std::endl;
    std::system("sudo apt -qq -y install npm");

    std::cout << "Adding package 'express' ..." << std::endl;
    std::system("sudo npm install express");
}