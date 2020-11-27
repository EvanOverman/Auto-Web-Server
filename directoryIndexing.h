// directoryIndexing.h
// Evan Overman
// Created Oct 22, 2020

namespace dirIndexing
{
	std::vector <std::string> makeDirIndex(std::string name) // Create a dirIndex file to index the current directory
	{
		std::string dirIndex;
		std::string fileLine;
		std::string list = "ls > " + name;
		std::fstream dirIndexFile;

		system(list.c_str()); // Create and populate the dirIndex file with files/folders
		dirIndexFile.open(name); // Open that file

		while(std::getline(dirIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			dirIndex += fileLine + " "; // Add the line and a space to follow
		}

		dirIndexFile.close();
		return(splitString(dirIndex, ' ')); // Split the dirIndex into a vector and return that object
	}

	std::vector <std::string> makeSimpleDirIndex(void) // Create a dirIndex file to index the current directory
	{
		std::string dirIndex;
		std::string fileLine;
		std::fstream dirIndexFile;

		system("ls simple > simpleDirIndex"); // Create and populate the dirIndex file with files/folders
		dirIndexFile.open("simpleDirIndex"); // Open that file

		while(std::getline(dirIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			dirIndex += fileLine + " "; // Add the line and a space to follow
		}

		dirIndexFile.close();
		return(splitString(dirIndex, ' ')); // Split the dirIndex into a vector and return that object
	}

	void makeOrgDirIndex(void) // Create a dirIndex file to index the current directory and the folders "pages", "pictures", "css", "js", and "downloads"
	{
		std::string dirIndex;
		std::string fileLine;
		std::fstream dirIndexFile;

		system("ls organized > dirIndex"); // Create and populate the dirIndex file with files/folders
		dirIndexFile.open("dirIndex"); // Open that file

		while(std::getline(dirIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			dirIndex += fileLine + " "; // Add the line and a space to follow
		}

		dirIndexFile.close(); // Close file to save resources

		std::string pagesIndex;
		std::fstream pagesIndexFile;

		system("ls organized/pages > pagesDirIndex"); // Create and populate the dirIndex file with files/folders
		pagesIndexFile.open("pagesDirIndex"); // Open that file

		while(std::getline(pagesIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			pagesIndex += fileLine + " "; // Add the line and a space to follow
		}

		pagesIndexFile.close(); // Close file to save resources

		std::string picturesIndex;
		std::fstream picturesIndexFile;

		system("ls organized/pictures > picturesDirIndex"); // Create and populate the dirIndex file with files/folders
		picturesIndexFile.open("picturesDirIndex"); // Open that file

		while(std::getline(picturesIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			picturesIndex += fileLine + " "; // Add the line and a space to follow
		}

		picturesIndexFile.close(); // Close file to save resources

		std::string cssIndex;
		std::fstream cssIndexFile;

		system("ls organized/css > cssDirIndex"); // Create and populate the dirIndex file with files/folders
		cssIndexFile.open("cssDirIndex"); // Open that file

		while(std::getline(cssIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			cssIndex += fileLine + " "; // Add the line and a space to follow
		}

		cssIndexFile.close(); // Close file to save resources

		std::string jsIndex;
		std::fstream jsIndexFile;

		system("ls organized/js > jsDirIndex"); // Create and populate the dirIndex.ls file with files/folders
		jsIndexFile.open("jsDirIndex"); // Open that file

		while(std::getline(jsIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			jsIndex += fileLine + " "; // Add the line and a space to follow
		}

		jsIndexFile.close(); // Close file to save resources

		std::string downloadsIndex;
		std::fstream downloadsIndexFile;

		system("ls organized/downloads > downloadsDirIndex"); // Create and populate the dirIndex.ls file with files/folders
		downloadsIndexFile.open("downloadsDirIndex"); // Open that file

		while(getline(downloadsIndexFile, fileLine)) // Loop through the file and add its lines to the dirInexVect vector object
		{ 
			downloadsIndex += fileLine + " "; // Add the line and a space to follow
		}

		downloadsIndexFile.close(); // Close file to save resources
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
