// serverJS.h
// Evan Overman
// Created Oct 22, 2020
// Last update: Oct 23, 2020

// This function takes a file name, and creates a code block for the server.js file
static string makeGet(string fileName) {

	return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '/simple/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");

}

static string makeOrgGet(string fileName) {

	return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '/organized/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");

}

static string makeOrgDownload(string fileName) {

	return("app.get('/" + fileName + "', (req, res) => {\nres.download(path.join(__dirname + '/organized/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");

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

// This funtion will do the same as a previous but will be used for the organized format
void makeOrgServerJS(string dirIndexName, string pagesDirIndexName, string picturesDirIndexName, string cssDirIndexName, string jsDirIndexName, string downloadsDirIndexName, string port) {

	system("rm server.js");

	fstream dirIndex(dirIndexName, ios::in);
	fstream pagesDirIndex(pagesDirIndexName, ios::in);
	fstream picturesDirIndex(picturesDirIndexName, ios::in);
	fstream cssDirIndex(cssDirIndexName, ios::in);
	fstream jsDirIndex(jsDirIndexName, ios::in);
	fstream downloadsDirIndex(downloadsDirIndexName, ios::in);

	fstream serverJS("server.js", ios::app);
	string fileName;

	serverJS << "express = require('express');\npath = require('path');\napp = express();\n\n";

	while(getline(dirIndex, fileName)) {

		serverJS << makeOrgGet(fileName);

	}

	while(getline(pagesDirIndex, fileName)) {

		serverJS << makeOrgGet("pages/" + fileName);

	}

	while(getline(picturesDirIndex, fileName)) {

		serverJS << makeOrgGet("pictures/" + fileName);

	}

	while(getline(cssDirIndex, fileName)) {

		serverJS << makeOrgGet("css/" + fileName);

	}

	while(getline(jsDirIndex, fileName)) {

		serverJS << makeOrgGet("js/" + fileName);

	}

	while(getline(downloadsDirIndex, fileName)) {

		serverJS << makeOrgDownload("downloads/" + fileName);

	}

	serverJS << "app.listen(" + port + ", console.log('Server listening on port " + port + "'));";

	dirIndex.close();
	pagesDirIndex.close();
	picturesDirIndex.close();
	cssDirIndex.close();
	jsDirIndex.close();
	downloadsDirIndex.close();

	serverJS.close();

}