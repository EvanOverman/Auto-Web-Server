/*

Evan Overman
express.hpp
Created 11/28/2020

*/

namespace express // Functions for making code to be used in a Node.js file using the Express package.
{
	struct standard // Standard, unchanging bits of Node.js for an Express based server.
	{
		public:
			std::string import = "express = require('express');\n"
								 "path = require('path');\n"; // Imports the Express package.

			std::string indexRedirect = "express.get('/', (req, res) => {"
				  						"\n\tres.redirect(path.join(__dirname + 'index.html'));"
				  						"\n\tconsole.log('Got request for / ... ');\n"
				  						"});\n\n";

			std::string listen = "app.listen(80, console.log('Server listening on port 80'));"; // Listens on port 80, standard for HTTP.
	};

	std::string indexRedirect (std::string index = "index.html") // Redirects to a page, normally index.html, unless otherwise specified.
	{
		std::string get;

		if (index[0] == '/')
		{
			get = "express.get('/', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '" + index + "'));"
				  "\n\tconsole.log('Got request for / ... ');\n"
				  "});\n\n";
		}

		else
		{
			get = "express.get('/', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '/" + index + "'));"
				  "\n\tconsole.log('Got request for / ... ');\n"
				  "});\n\n";
		}
		
		return get;
	}

	std::string get (std::string file) // Makes an express.get() function statement to host a specified file.
	{
		std::string get;

		if (file[0] == '/')
		{
			get = "express.get('" + file + "', (req, res) => {"
				  "\n\tres.sendFile(path.join(__dirname + '" + file + "'));"
				  "\n\tconsole.log('Got request for " + file + " ... ');\n"
				  "});\n\n";
		}

		else
		{
			get = "express.get('/" + file + "', (req, res) => {"
				  "\n\tres.sendFile(path.join(__dirname + '/" + file + "'));"
				  "\n\tconsole.log('Got request for /" + file + " ... ');\n"
				  "});\n\n";
		}
		
		return get;
	}

	std::string download (std::string file) // Makes an express.get() function statement to download a specific file.
	{
		std::string get;

		if (file[0] == '/')
		{
			get = "express.get('" + file + "', (req, res) => {"
				  "\n\tres.download(path.join(__dirname + '" + file + "'));"
				  "\n\tconsole.log('Got request for " + file + " ... ');\n"
				  "});\n\n";
		}

		else
		{
			get = "express.get('/" + file + "', (req, res) => {"
				  "\n\tres.download(path.join(__dirname + '/" + file + "'));"
				  "\n\tconsole.log('Got request for /" + file + " ... ');\n"
				  "});\n\n";
		}
		
		return get;
	}

	std::string listen (int port = 80)
	{
		std::string listen = "app.listen(" + std::to_string(port) + ", console.log('Server listening on port " + std::to_string(port) + "'));";
		return listen;
	}

}