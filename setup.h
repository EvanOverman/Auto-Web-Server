// setup.h
// Evan Overman
// Created Nov 19, 2020

namespace setup
{
    void debianSetup(void) // Run setup commands, in the future the setup funtion may be made to also support arch based systems.
    {
        std::cout << "Sarting setup ..." << std::endl;

        std::cout << "Making directory 'simple' ..." << std::endl;
        system("mkdir simple");
        std::cout << "Making directory 'organized' ..." << std::endl;
        system("mkdir organized");
        std::cout << "Making directory 'organized/pages' ..." << std::endl;
        system("mkdir organized/pages");
        std::cout << "Making directory 'organized/css' ..." << std::endl;
        system("mkdir organized/css");
        std::cout << "Making directory 'organized/js' ..." << std::endl;
        system("mkdir organized/js");
        std::cout << "Making directory 'organized/pictures' ..." << std::endl;
        system("mkdir organized/pictures");
        std::cout << "Making directory 'organized/downloads' ..." << std::endl;
        system("mkdir organized/downloads");
        std::cout << "Making directory 'dirIndexies' ..." << std::endl;
        system("mkdir dirIndexies");

        std::cout << "Making and populating 'dirIndex' ..." << std::endl;
        system("ls organized > dirIndex");
        std::cout << "Making and populating 'simpleDirIndex' ..." << std::endl;
        system("ls simple > simpleDirIndex");
        std::cout << "Making and populating 'pagesDirIndex' ..." << std::endl;
        system("ls organized/pages > pagesDirIndex");
        std::cout << "Making and populating 'cssDirIndex' ..." << std::endl;
        system("ls organized/css > cssDirIndex");
        std::cout << "Making and populating 'jsDirIndex' ..." << std::endl;
        system("ls organized/js > jsDirIndex");
        std::cout << "Making and populating 'picturesDirIndex' ..." << std::endl;
        system("ls organized/pictures > picturesDirIndex");
        std::cout << "Making and populating 'downloadsDirIndex' ..." << std::endl;
        system("ls organized/downloads > downloadsDirIndex");

        std::cout << "Making 'server.js' ..." << std::endl;
        system("echo 'No content yet, run Auto-Web-Server to populate this file.' > server.js");

        std::cout << "Updating reposity list, you may be prompted for your password ..." << std::endl;
        system("sudo apt -qq -y update");
        std::cout << "Installing Node.js ..." << std::endl;
        system("sudo apt -qq -y install nodejs");
        std::cout << "Installing npm ..." << std::endl;
        system("sudo apt -qq -y install npm");

        std::cout << "Adding package 'express' ..." << std::endl;
        system("sudo npm install express");
    }
}
