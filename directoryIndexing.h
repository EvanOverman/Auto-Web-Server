// directoryIndexing.h
// Evan Overman
// Created Oct 22, 2020
// Last update: Nov 19, 2020

#include <string>
#include <fstream>

using namespace std;
using std::vector;

static vector <string> splitString(string text, char split) // Splits one string into many by dividing it whenever the char "split" appears
{ 
    vector <string> splitText; // Create a vector for the split strings
    size_t position = text.find(split); // Check if the text contains the char "split", if so will return string::npos
    size_t initialPosition = 0;

    while(position != string::npos) // if the text contains the char "split", split it by the char "split"
	{ 
        splitText.push_back(text.substr(initialPosition, position - initialPosition));
        initialPosition = position + 1;
        position = text.find(split, initialPosition);
    }

    splitText.push_back(text.substr(initialPosition, min(position, text.size()) - initialPosition + 1));
    return splitText;
}

vector <string> makeDirIndex(void) // Create a dirIndex.ls file to index the current directory
{
	string dirIndex;
	string fileLine;
	fstream dirIndexFile;
	system("ls simple > simpleDirIndex"); // Create and populate the dirIndex.ls file with files/folders
	dirIndexFile.open("simpleDirIndex"); // Open that file

	while(getline(dirIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		dirIndex += fileLine + " "; // Add the line and a space to follow
	}

	dirIndexFile.close();
	return(splitString(dirIndex, ' ')); // Split the dirIndex into a vector and return that object
}

void makeOrgDirIndex(void) // Create a dirIndex.ls file to index the current directory and the folders "pages", "pictures", "css", "js", and "downloads"
{
	string dirIndex;
	string fileLine;
	fstream dirIndexFile;

	system("ls organized > dirIndex"); // Create and populate the dirIndex.ls file with files/folders
	dirIndexFile.open("dirIndex"); // Open that file

	while(getline(dirIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		dirIndex += fileLine + " "; // Add the line and a space to follow
	}

	dirIndexFile.close(); // Close file to save resources

	string pagesIndex;
	fstream pagesIndexFile;

	system("ls organized/pages > pagesDirIndex"); // Create and populate the dirIndex.ls file with files/folders
	pagesIndexFile.open("pagesDirIndex"); // Open that file

	while(getline(pagesIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		pagesIndex += fileLine + " "; // Add the line and a space to follow
	}

	pagesIndexFile.close(); // Close file to save resources

	string picturesIndex;
	fstream picturesIndexFile;

	system("ls organized/pictures > picturesDirIndex"); // Create and populate the dirIndex.ls file with files/folders
	picturesIndexFile.open("picturesDirIndex"); // Open that file

	while(getline(picturesIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		picturesIndex += fileLine + " "; // Add the line and a space to follow
	}

	picturesIndexFile.close(); // Close file to save resources

	string cssIndex;
	fstream cssIndexFile;

	system("ls organized/css > cssDirIndex"); // Create and populate the dirIndex.ls file with files/folders
	cssIndexFile.open("cssDirIndex"); // Open that file

	while(getline(cssIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		cssIndex += fileLine + " "; // Add the line and a space to follow
	}

	cssIndexFile.close(); // Close file to save resources

	string jsIndex;
	fstream jsIndexFile;

	system("ls organized/js > jsDirIndex"); // Create and populate the dirIndex.ls file with files/folders
	jsIndexFile.open("jsDirIndex"); // Open that file

	while(getline(jsIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		jsIndex += fileLine + " "; // Add the line and a space to follow
	}

	jsIndexFile.close(); // Close file to save resources

	string downloadsIndex;
	fstream downloadsIndexFile;

	system("ls organized/downloads > downloadsDirIndex"); // Create and populate the dirIndex.ls file with files/folders
	downloadsIndexFile.open("downloadsDirIndex"); // Open that file

	while(getline(downloadsIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
	{ 
		downloadsIndex += fileLine + " "; // Add the line and a space to follow
	}

	downloadsIndexFile.close(); // Close file to save resources
}

vector <string> readDirIndex(string fileName) 
{
	string dirIndex;
	string fileLine;
	fstream dirIndexFile;
	dirIndexFile.open(fileName, ios::in);

	while(getline(dirIndexFile, fileLine)) 
	{
		dirIndex += fileLine + " ";
	}

	return(splitString(dirIndex, ' '));
}