// serverJS.h
// Evan Overman
// Created Oct 22, 2020
// Last update: Oct 22, 2020

// This function takes a file name, and creates a code block for the server.js file
static string makeGet(string fileName) {

	return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");

}

// This function will use the previous to create an entire server.js file.
// it will read the dirIndex.ls file (or other specified list) and make the file based on that.
void makeServerJS(string dirIndexName, string port) {

	system("rm server.js");
	fstream dirIndex(dirIndexName, ios::in);
	fstream serverJS("server.js", ios::app);
	string fileName;

	serverJS << "express = require('express');\npath = require('path');\napp = express();\n\n";

	while(getline(dirIndex, fileName)) {

		serverJS << makeGet(fileName);

	}

	serverJS << "app.listen(" + port + ", console.log('Server listening on port " + port + "'));";

}