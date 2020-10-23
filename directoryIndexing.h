// directoryIndexing.h
// Evan Overman
// Created Oct 22, 2020
// Last update: Oct 22, 2020

#include <string>
#include <fstream>

using namespace std;
using std::vector;

// Splits one string into many by dividing it whenever the char "split" appears
static vector <string> splitString(string text, char split) { 

    vector <string> splitText; // Create a vector for the split strings

    size_t position = text.find(split); // Check if the text contains the char "split", if so will return string::npos
    size_t initialPosition = 0;

    while(position != string::npos) { // if the text contains the char "split", split it by the char "split"

        splitText.push_back(text.substr(initialPosition, position - initialPosition));
        initialPosition = position + 1;

        position = text.find(split, initialPosition);

    }

    splitText.push_back(text.substr(initialPosition, min(position, text.size()) - initialPosition + 1));

    return splitText;

}

// Create an dirIndex.ls file to index the current directory
vector <string> makeDirIndex(void) {

	string dirIndex;
	string fileLine;
	fstream dirIndexFile;
	system("ls > dirIndex.ls"); // Create and populate the dirIndex.ls file with files/folders
	dirIndexFile.open("dirIndex.ls"); // Open that file

	while(getline(dirIndexFile, fileLine)) { // Loop through the file and add its lines to the dirInexVect vector object
		dirIndex += fileLine + " "; // Add the line and a space to follow
	}

	return(splitString(dirIndex, ' ')); // Split the dirIndex into a vector and return that object

}

