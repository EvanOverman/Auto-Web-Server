// serverJS.h
// Evan Overman
// Created Oct 22, 2020
// Last update: Oct 23, 2020

// These functions takes a file name, and creates a code block for the server.js file.
static string makeGet(string fileName) // Make a basic app.get() function.
{
	return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '/simple/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");
}

static string makeOrgGet(string fileName) // Make an app.get() function for the organized format.
{
	return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '/organized/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");
}

static string makeOrgDownload(string fileName) // Make an app.get() that responds with a download.
{
	return("app.get('/" + fileName + "', (req, res) => {\nres.download(path.join(__dirname + '/organized/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");
}

static string makeFirstGet() // Make an app.get() funtion that redirects to index.html in the organized format.
{
	return("app.get('/', (req, res) => {\nres.redirect(path.join('/index.html'));\nconsole.log('Got request for / ... ');\n});\n\n");
}

void makeServerJS(string dirIndexName, string port) // This function will use the previous to create an entire server.js file, it will read the dirIndex.ls file (or other specified list) and make the file based on that.
{
	system("rm server.js");

	fstream dirIndex(dirIndexName, ios::in);
	fstream serverJS("server.js", ios::app);
	string fileName;

	serverJS << "express = require('express');\npath = require('path');\napp = express();\n\n";

	while(getline(dirIndex, fileName)) 
	{
		serverJS << makeGet(fileName);
	}

	serverJS << "app.listen(" + port + ", console.log('Server listening on port " + port + "'));";
}

void makeOrgServerJS(string dirIndexName, string pagesDirIndexName, string picturesDirIndexName, string cssDirIndexName, string jsDirIndexName, string downloadsDirIndexName, string port) // This funtion will do the same as a previous but will be used for the organized format
{
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

	serverJS << makeFirstGet();

	while(getline(dirIndex, fileName)) 
	{
		serverJS << makeOrgGet(fileName);
	}

	while(getline(pagesDirIndex, fileName)) 
	{
		serverJS << makeOrgGet("pages/" + fileName);
	}

	while(getline(picturesDirIndex, fileName)) 
	{
		serverJS << makeOrgGet("pictures/" + fileName);
	}

	while(getline(cssDirIndex, fileName)) 
	{
		serverJS << makeOrgGet("css/" + fileName);
	}

	while(getline(jsDirIndex, fileName))
	{
		serverJS << makeOrgGet("js/" + fileName);
	}

	while(getline(downloadsDirIndex, fileName)) 
	{
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