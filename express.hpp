/*

Evan Overman
express.hpp
Created 11/28/2020

*/

namespace express // Functions for making code to be used in a Node.js file using the Express package.
{
	std::string import (std::string pkg) // Imports the given package (pkg).
	{
		std::string import = "const " + pkg + " = require('" + pkg + "');\n"; // Makes a require() statement for the given package.
		return import;
	}

	std::string indexRedirect (std::string index = "index.html") // Redirects to a page, normally index.html, unless otherwise specified.
	{
		std::string get;

		if (index[0] == '/')
		{
			get = "\nexpress.get('/', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '" + index + "'));"
				  "\n\tconsole.log('Got request for / ... ');\n"
				  "});\n\n"; // Redirects to the given file from "/".
		}

		else
		{
			get = "express.get('/', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '/" + index + "'));"
				  "\n\tconsole.log('Got request for / ... ');\n"
				  "});\n\n"; // Redirects to the given file from "/".
		}
		
		return get;
	}

	std::string redirect (std::string from = "/", std::string to = "index.html") // Redirects to a page, normally index.html, unless otherwise specified.
	{
		std::string get;

		if (to[0] == '/' && from[0] == '/')
		{
			get = "\nexpress.get('" + from + "', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '" + to + "'));"
				  "\n\tconsole.log('Got request for " + from + " ... ');\n"
				  "});\n\n"; 
		}

		else if (to[0] == '/' && from[0] != '/')
		{
			get = "\nexpress.get('/" + from + "', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '" + to + "'));"
				  "\n\tconsole.log('Got request for /" + from + " ... ');\n"
				  "});\n\n"; 
		}

		else if (to[0] != '/' && from[0] == '/')
		{
			get = "\nexpress.get('" + from + "', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '/" + to + "'));"
				  "\n\tconsole.log('Got request for " + from + " ... ');\n"
				  "});\n\n"; 
		}

		else
		{
			get = "express.get('/" + from + "', (req, res) => {"
				  "\n\tres.redirect(path.join(__dirname + '/" + to + "'));"
				  "\n\tconsole.log('Got request for /" + from + " ... ');\n"
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
				  "});\n\n"; // Hosts a file using express.
		}

		else
		{
			get = "express.get('/" + file + "', (req, res) => {"
				  "\n\tres.sendFile(path.join(__dirname + '/" + file + "'));"
				  "\n\tconsole.log('Got request for /" + file + " ... ');\n"
				  "});\n\n"; // Hosts a file using express.
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
				  "});\n\n"; // Hosts a file to download using express.
		}

		else
		{
			get = "express.get('/" + file + "', (req, res) => {"
				  "\n\tres.download(path.join(__dirname + '/" + file + "'));"
				  "\n\tconsole.log('Got request for /" + file + " ... ');\n"
				  "});\n\n"; // Hosts a file to download using express.
		}
		
		return get;
	}

	std::string listen (std::string port = "80") // Makes an expres.listen() function
	{
		std::string listen = "express.listen(" + port + ", console.log('Server listening on port " + port + "'));"; // Server listens on given port using express.
		return listen;
	}

	class node
	{
		private:
			std::string file;
			std::fstream nodejs;

		public:

			void clear () // express::node server; server.open("server.js"); 
			{
				nodejs.clear();
			}

			void makeFile (std::string _file)
			{
				file = _file;
			}

			void redirect (std::string from, std::string to)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << express::redirect(from, to);
				nodejs.close();
			}

			void import (std::string pkg)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << express::import(pkg);
				nodejs.close();
			}

			void get (std::string _file)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << express::get(_file);
				nodejs.close();
			}

			void download (std::string _file)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << express::download(_file);
				nodejs.close();
			}

			void listen (std::string port = "80")
			{
				nodejs.open(file, std::fstream::app);
				nodejs << express::listen(port);
				nodejs.close();
			}

	};

}