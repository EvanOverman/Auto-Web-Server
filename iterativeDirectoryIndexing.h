// iterativeDirectoryIndexing.h
// Evan Overman
// Created Oct 25, 2020
// Last update: Oct 25, 2020

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

	while(getline(iterativeDirIndex, fileLine)) {

		if(fileLine.find('.') == string::npos) {

			iterativeDirIndexingSH << "#!/bin/bash\nls " + fileLine + " > tempDirIndex.ls";
			fstream tempDirIndex("tempDirIndex.ls", ios::in);

			while(getline(tempDirIndex, tempFileLine)) {
				iterativeDirIndex << fileLine + "/" + tempFileLine;
			}

			tempDirIndex.close();
		}

	}

}