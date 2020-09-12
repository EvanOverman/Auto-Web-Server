#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <string>

#include "directoryIndexing.h"

using namespace std;

vector <string> splitString(string text, char split) {

    vector <string> splitText;

    size_t position = text.find(split);
    size_t initialPosition = 0;

    splitText.clear();

    while(position != string::npos) {

        splitText.push_back(text.substr(initialPosition, position - initialPosition));
        initialPosition = position + 1;

        position = text.find(split, initialPosition);

    }

    splitText.push_back(text.substr(initialPosition, min(position, text.size()) - initialPosition + 1));

    return splitText;

}

vector <string> findSubDirectories(vector <string> directoryIndex) {

    vector <string> subDirectories;
    subDirectories.cbegin();

    int position = 0;

    for(int directoryIndexPosition = 0; directoryIndexPosition >= directoryIndex.size(); directoryIndexPosition++) {

        if(directoryIndex[directoryIndexPosition].find(".") != true) {

            subDirectories.insert(position, directoryIndex[directoryIndexPosition]);

        }

    }

    return subDirectories;

}

vector <string> createIterativeDirectoryIndex(void) {

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

void updateIterativeDirectoryIndex(void) {

    fstream directoryIndexLS;
    directoryIndexLS.open("directoryIndex.ls");

    directoryIndexLS << "";
    system("ls > directoryIndex.ls");

    directoryIndexLS.close();

}