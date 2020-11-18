// iterativeDirectoryIndexing.h
// Evan Overman
// Created Oct 25, 2020
// Last update: Oct 27, 2020

#include <string>
#include <fstream>

using namespace std;
using std::vector;

// This funtion will make a directory index that includes any and all subdirectories and their folders
// NOTE: in some cases this could produce a signifigant performance hit
bool makeIterativeDirIndex(void) {

	bool iterated = false;
	string fileLine;
	string tempFileLine;
	fstream iterativeDirIndex("iterativeDirIndex", ios::app);
	fstream tempDirIndex("tempDirIndex", ios::in);

	while(getline(iterativeDirIndex, fileLine)) {

		if(fileLine.find('.') == string::npos) {

			if(iterated != true) {
				iterated = true;
			}

			fstream iterativeDirIndexingSH("iterativeDirIndexing.sh", ios::out);
			iterativeDirIndexingSH << "#!/bin/bash" << endl << "ls " << fileLine << " > tempDirIndex" << endl;
			iterativeDirIndexingSH.close();	

			system("./iterativeDirIndexing");

			while(getline(tempDirIndex, tempFileLine)) {
				iterativeDirIndex << fileLine << "/" << tempFileLine << endl;
			}

		}

	}

	iterativeDirIndex.close();
	tempDirIndex.close();

	return iterated;

}