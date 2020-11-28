// serverJS.h
// Evan Overman
// Created Oct 22, 2020

namespace express // These functions takes a file name, and creates a code block for the server.js file.
{
	static std::string makeFirstGet(void) // Make an app.get() funtion that redirects to index.html in the organized format.
	{
		return("app.get('/', (req, res) => {\nres.redirect(path.join('/index.html'));\nconsole.log('Got request for / ... ');\n});\n\n");
	}

	static std::string makeGet(std::string fileName) // Make a basic app.get() function.
	{
		return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '/simple/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");
	}

	static std::string makeOrgGet(std::string fileName) // Make an app.get() function for the organized format.
	{
		return("app.get('/" + fileName + "', (req, res) => {\nres.sendFile(path.join(__dirname + '/organized/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");
	}

	static std::string makeOrgDownload(std::string fileName) // Make an app.get() that responds with a download.
	{
		return("app.get('/" + fileName + "', (req, res) => {\nres.download(path.join(__dirname + '/organized/" + fileName + "'));\nconsole.log('Got request for /" + fileName + " ... ');\n});\n\n");
	}
}

namespace node
{
	void makeServerJS(std::string dirIndexName, std::string port) // This function will use the previous to create an entire server.js file, it will read the dirIndex.ls file (or other specified list) and make the file based on that.
	{
		system("rm server.js");

		std::fstream dirIndex(dirIndexName, std::ios::in);
		std::fstream serverJS("server.js", std::ios::app);
		std::string fileName;

		serverJS << "express = require('express');\npath = require('path');\napp = express();\n\n";

		while(std::getline(dirIndex, fileName)) 
		{
			serverJS << express::makeGet(fileName);
		}

		serverJS << "app.listen(" + port + ", console.log('Server listening on port " + port + "'));";
	}

	void makeOrgServerJS(std::string dirIndexName, std::string pagesDirIndexName, std::string picturesDirIndexName, std::string cssDirIndexName, std::string jsDirIndexName, std::string downloadsDirIndexName, std::string port) // This funtion will do the same as a previous but will be used for the organized format
	{
		system("rm server.js");

		std::fstream dirIndex(dirIndexName, std::ios::in);
		std::fstream pagesDirIndex(pagesDirIndexName, std::ios::in);
		std::fstream picturesDirIndex(picturesDirIndexName, std::ios::in);
		std::fstream cssDirIndex(cssDirIndexName, std::ios::in);
		std::fstream jsDirIndex(jsDirIndexName, std::ios::in);
		std::fstream downloadsDirIndex(downloadsDirIndexName, std::ios::in);

		std::fstream serverJS("server.js", std::ios::app);
		std::string fileName;

		serverJS << "express = require('express');\npath = require('path');\napp = express();\n\n";

		serverJS << express::makeFirstGet();

		while(std::getline(dirIndex, fileName)) 
		{
			serverJS << express::makeOrgGet(fileName);
		}

		while(std::getline(pagesDirIndex, fileName)) 
		{
			serverJS << express::makeOrgGet("pages/" + fileName);
		}

		while(std::getline(picturesDirIndex, fileName)) 
		{
			serverJS << express::makeOrgGet("pictures/" + fileName);
		}

		while(std::getline(cssDirIndex, fileName)) 
		{
			serverJS << express::makeOrgGet("css/" + fileName);
		}

		while(std::getline(jsDirIndex, fileName))
		{
			serverJS << express::makeOrgGet("js/" + fileName);
		}

		while(std::getline(downloadsDirIndex, fileName)) 
		{
			serverJS << express::makeOrgDownload("downloads/" + fileName);
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
}
