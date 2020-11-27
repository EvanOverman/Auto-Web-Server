// directoryIndexing.h
// Evan Overman
// Created Oct 22, 2020

namespace dirIndexing
{
	std::vector <std::string> makeDirIndex(std::string dir, std::string name) // Create a dirIndex file to index the current directory
	{
		std::string dirIndex;
		std::string fileLine;
		std::string list;
		std::fstream dirIndexFile;

		if (dir == "none") // User has not given directory to be indexed.
		{
			std::string list = "ls > " + name; // Make index of current directory.
		}
		else
		{
			std::string list = "ls " + dir + " > " + name; // Make index of specified directory.
		}

		system(list.c_str()); // Create and populate the dirIndex file with files/folders
		dirIndexFile.open(name); // Open that file

		while(std::getline(dirIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			dirIndex += fileLine + " "; // Add the line and a space to follow
		}

		dirIndexFile.close();
		return(splitString(dirIndex, ' ')); // Split the dirIndex into a vector and return that object
	}

	namespace compounds 
	{
		void makeSimpleDirIndex(void) // Create a dirIndex file to index the current directory
		{
			makeDirIndex("simple", "dirIndexies/simpleDirIndex");
		}

		void makeOrgDirIndex(void) // Create a dirIndex file to index the current directory and the folders "pages", "pictures", "css", "js", and "downloads"
		{
			makeDirIndex("organized", "dirIndexies/dirIndex");
			makeDirIndex("organized/pages", "dirIndexies/pagesDirIndex");
			makeDirIndex("organized/pictures", "dirIndexies/picturesDirIndex");
			makeDirIndex("organized/css", "dirIndexies/cssDirIndex");
			makeDirIndex("organized/js", "dirIndexies/jsDirIndex");
			makeDirIndex("organized/downloads", "dirIndexies/downloads");
		}
	}
	
	std::vector <std::string> readDirIndex(std::string fileName) 
	{
		std::string dirIndex;
		std::string fileLine;
		std::fstream dirIndexFile;
		dirIndexFile.open(fileName, std::ios::in);

		while(std::getline(dirIndexFile, fileLine)) 
		{
			dirIndex += fileLine + " ";
		}

		return(splitString(dirIndex, ' '));
	}
}
