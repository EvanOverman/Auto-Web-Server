/*

Evan Overman
express.hpp
Created 11/29/2020

*/

namespace express
{
	namespace paths
	{
		struct code_blocks
		{
			std::string import (std::string pkg)
			{
				std::string import = "const " + pkg + " = require('" + pkg + "');\n";

				if (pkg == "express")
				{
					import += "app = express();\n";
				}

				return import;
			}

			std::string indexRedirect (std::filesystem::path _index)
			{
				std::string get;
				std::string index = _index.string();

				if (index[0] == '.')
                {
                    index.erase(0, 1);
                }

                std::replace(index.begin(), index.end(), '\\', '/');

				if (index[0] == '/')
				{
					get = "\napp.get('/', (req, res) => {"
						"\n\tres.redirect(path.join(__dirname + '" + index + "'));"
						"\n\tconsole.log('Got request for / ... ');\n"
						"});\n\n"; // Redirects to the given file from "/".
				}

				else
				{
					get = "\napp.get('/', (req, res) => {"
						"\n\tres.redirect(path.join(__dirname + '/" + index + "'));"
						"\n\tconsole.log('Got request for / ... ');\n"
						"});\n\n"; // Redirects to the given file from "/".
				}
				
				return get;
			}

			std::string redirect (std::filesystem::path _to, std::string from = "/")
			{
				std::string get;
				std::string to = _to.string();

				if (to[0] == '.')
                {
                    to.erase(0, 1);
                }

                std::replace(to.begin(), to.end(), '\\', '/');

				if (to[0] == '/' && from[0] == '/')
				{
					get = "\napp.get('" + from + "', (req, res) => {"
						"\n\tres.redirect(path.join(__dirname + '" + to + "'));"
						"\n\tconsole.log('Got request for " + from + " ... ');\n"
						"});\n\n"; 
				}

				else if (to[0] == '/' && from[0] != '/')
				{
					get = "\napp.get('/" + from + "', (req, res) => {"
						"\n\tres.redirect(path.join(__dirname + '" + to + "'));"
						"\n\tconsole.log('Got request for /" + from + " ... ');\n"
						"});\n\n"; 
				}

				else if (to[0] != '/' && from[0] == '/')
				{
					get = "\napp.get('" + from + "', (req, res) => {"
						"\n\tres.redirect(path.join(__dirname + '/" + to + "'));"
						"\n\tconsole.log('Got request for " + from + " ... ');\n"
						"});\n\n"; 
				}

				else
				{
					get = "\napp.get('/" + from + "', (req, res) => {"
						"\n\tres.redirect(path.join(__dirname + '/" + to + "'));"
						"\n\tconsole.log('Got request for /" + from + " ... ');\n"
						"});\n\n"; 
				}
				
				return get;
			}

			std::string get (std::filesystem::path _file)
			{
				std::string get;
				std::string file = _file.string();

				if (file[0] == '.')
                {
                    file.erase(0, 1);
                }

                std::replace(file.begin(), file.end(), '\\', '/');

				if (file[0] == '/')
				{
					get = "\napp.get('" + file + "', (req, res) => {"
						"\n\tres.sendFile(path.join(__dirname + '" + file + "'));"
						"\n\tconsole.log('Got request for " + file + " ... ');\n"
						"});\n\n"; // Hosts a file using express.
				}

				else
				{
					get = "\napp.get('/" + file + "', (req, res) => {"
						"\n\tres.sendFile(path.join(__dirname + '/" + file + "'));"
						"\n\tconsole.log('Got request for /" + file + " ... ');\n"
						"});\n\n"; // Hosts a file using express.
				}
				
				return get;
			}

			std::string download (std::filesystem::path _file) 
			{
				std::string get;
				std::string file = _file.string();

				if (file[0] == '.')
                {
                    file.erase(0, 1);
                }

                std::replace(file.begin(), file.end(), '\\', '/');

				if (file[0] == '/')
				{
					get = "\napp.get('" + file + "', (req, res) => {"
						"\n\tres.download(path.join(__dirname + '" + file + "'));"
						"\n\tconsole.log('Got request for " + file + " ... ');\n"
						"});\n\n"; // Hosts a file to download using express.
				}

				else
				{
					get = "\napp.get('/" + file + "', (req, res) => {"
						"\n\tres.download(path.join(__dirname + '/" + file + "'));"
						"\n\tconsole.log('Got request for /" + file + " ... ');\n"
						"});\n\n"; // Hosts a file to download using express.
				}
				
				return get;
			}

			std::string listen (int port) 
			{
				std::string listen = "\napp.listen(" + std::to_string(port) + ", console.log('Server listening on port " + std::to_string(port) + "'));";
				return listen;
			}

		};
		
	}

	struct code_blocks
	{
		std::string import (std::string pkg) // Imports the given package (pkg).
		{
			std::string import = "const " + pkg + " = require('" + pkg + "');\n";

			if (pkg == "express")
			{
				import += "app = express();\n";
			}

			return import;
		}

		std::string indexRedirect (std::string index = "index.html") // Redirects to a page, normally index.html, unless otherwise specified.
		{
			std::string get;

			if (index[0] == '/')
			{
				get = "\napp.get('/', (req, res) => {"
					"\n\tres.redirect(path.join(__dirname + '" + index + "'));"
					"\n\tconsole.log('Got request for / ... ');\n"
					"});\n\n"; // Redirects to the given file from "/".
			}

			else
			{
				get = "\napp.get('/', (req, res) => {"
					"\n\tres.redirect(path.join(__dirname + '/" + index + "'));"
					"\n\tconsole.log('Got request for / ... ');\n"
					"});\n\n"; // Redirects to the given file from "/".
			}
			
			return get;
		}

		std::string redirect (std::string from = "/", std::string to = "index.html") 
		{
			std::string get;

			if (to[0] == '/' && from[0] == '/')
			{
				get = "\napp.get('" + from + "', (req, res) => {"
					"\n\tres.redirect(path.join(__dirname + '" + to + "'));"
					"\n\tconsole.log('Got request for " + from + " ... ');\n"
					"});\n\n"; 
			}

			else if (to[0] == '/' && from[0] != '/')
			{
				get = "\napp.get('/" + from + "', (req, res) => {"
					"\n\tres.redirect(path.join(__dirname + '" + to + "'));"
					"\n\tconsole.log('Got request for /" + from + " ... ');\n"
					"});\n\n"; 
			}

			else if (to[0] != '/' && from[0] == '/')
			{
				get = "\napp.get('" + from + "', (req, res) => {"
					"\n\tres.redirect(path.join(__dirname + '/" + to + "'));"
					"\n\tconsole.log('Got request for " + from + " ... ');\n"
					"});\n\n"; 
			}

			else
			{
				get = "\napp.get('/" + from + "', (req, res) => {"
					"\n\tres.redirect(path.join(__dirname + '/" + to + "'));"
					"\n\tconsole.log('Got request for /" + from + " ... ');\n"
					"});\n\n"; 
			}
			
			return get;
		}

		std::string get (std::string file) // Makes an app.get() function statement to host a specified file.
		{
			std::string get;

			if (file[0] == '/')
			{
				get = "\napp.get('" + file + "', (req, res) => {"
					"\n\tres.sendFile(path.join(__dirname + '" + file + "'));"
					"\n\tconsole.log('Got request for " + file + " ... ');\n"
					"});\n\n"; // Hosts a file using express.
			}

			else
			{
				get = "\napp.get('/" + file + "', (req, res) => {"
					"\n\tres.sendFile(path.join(__dirname + '/" + file + "'));"
					"\n\tconsole.log('Got request for /" + file + " ... ');\n"
					"});\n\n"; // Hosts a file using express.
			}
			
			return get;
		}

		std::string download (std::string file) // Makes an app.get() function statement to download a specific file.
		{
			std::string get;

			if (file[0] == '/')
			{
				get = "\napp.get('" + file + "', (req, res) => {"
					"\n\tres.download(path.join(__dirname + '" + file + "'));"
					"\n\tconsole.log('Got request for " + file + " ... ');\n"
					"});\n\n"; // Hosts a file to download using express.
			}

			else
			{
				get = "\napp.get('/" + file + "', (req, res) => {"
					"\n\tres.download(path.join(__dirname + '/" + file + "'));"
					"\n\tconsole.log('Got request for /" + file + " ... ');\n"
					"});\n\n"; // Hosts a file to download using express.
			}
			
			return get;
		}

		std::string listen (int port) // Makes an expres.listen() function
		{
			std::string listen = "\napp.listen(" + std::to_string(port) + ", console.log('Server listening on port " + std::to_string(port) + "'));";
			return listen;
		}

	};
	
}