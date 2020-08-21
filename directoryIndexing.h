#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <string>

#include "main.cpp"

using namespace std;

vector <string> creatDirectoryIndex(void) {

    vector <string> directoryIndexVector;
    directoryIndexVector.cbegin();

    fstream directoryIndexLS;
    directoryIndexLS.open("directoryIndex.ls");

    directoryIndexLS << "";

    system("ls > directoryIndex.ls");

    string directoryIndex;
    string directoryIndexLine;

    while(getline(directoryIndexLS, directoryIndexLine)) {

        directoryIndex += directoryIndexLine;
        directoryIndex += " ";

    }

    directoryIndexVector = splitString(directoryIndex, ' ');
    directoryIndexLS.close();
    return directoryIndexVector;

}

void updateDirectoryIndex(void) {

    fstream directoryIndexLS;
    directoryIndexLS.open("directoryIndex.ls");

    directoryIndexLS << "";
    system("ls > directoryIndex.ls");

    directoryIndexLS.close();

}

vector <string> readDirectoryIndex(void) {

    vector <string> directoryIndexVector;
    directoryIndexVector.cbegin();

    fstream directoryIndexLS;
    directoryIndexLS.open("directoryIndex.ls");

    string directoryIndex;
    string directoryIndexLine;

    while(getline(directoryIndexLS, directoryIndexLine)) {

        directoryIndex += directoryIndexLine;
        directoryIndex += " ";

    }

    directoryIndexVector = splitString(directoryIndex, ' ');
    directoryIndexLS.close();
    return directoryIndexVector;

}