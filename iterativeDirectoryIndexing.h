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
vector <string> makeIterativeDirIndex(void) {

	string fileLine;
	string tempFileLine;
	fstream iterativeDirIndex("iterativeDirIndex.ls", ios::app);
	fstream iterativeDirIndexingSH("iterativeDirIndexing.sh", ios::app);
	fstream tempDirIndex("tempDirIndex.ls", ios::in);

	iterativeDirIndexingSH << "#!/bin/bash" << endl;

	while(getline(iterativeDirIndex, fileLine)) {

		if(fileLine.find('.') == string::npos) {

			iterativeDirIndexingSH << "ls " << fileLine << " > tempDirIndex.ls" << endl;

			while(getline(tempDirIndex, tempFileLine)) {
				iterativeDirIndex << fileLine << "/" << tempFileLine << endl;
			}

		}

	}

	iterativeDirIndex.close();
	iterativeDirIndexingSH.close();
	tempDirIndex.close();

}