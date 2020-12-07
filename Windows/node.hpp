/*

Evan Overman
node.hpp
Created 12/04/2020

*/

namespace node
{
	namespace paths
	{
		class js_file
		{
			private:
				express::paths::code_blocks code_blocks;
				std::filesystem::path file;
				std::fstream nodejs;

			public:
				void clear (const std::string _file) // express::node server; server.open("server.js"); 
				{
					remove(_file.c_str());
				}

				void open (std::filesystem::path _file)
				{
					file = _file;
				}

				void redirect (const std::filesystem::path to, const std::string from, const std::string space)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.redirect(to, from, space);
					nodejs.close();
				}

				void import (const std::string pkg)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.import(pkg);
					nodejs.close();
				}

				void get (const std::filesystem::path _file, const std::string space)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.get(_file, space);
					nodejs.close();
				}

				void download (const std::filesystem::path _file, const std::string space)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.download(_file, space);
					nodejs.close();
				}

				void listen (const int port)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.listen(port);
					nodejs.close();
				}

		};

	}

    class js_file
	{
		private:
			express::code_blocks code_blocks;
			std::string file;
			std::fstream nodejs;

		public:
			void clear (std::string _file) // express::node server; server.open("server.js"); 
			{
				remove(_file.c_str());
			}

			void open (std::string _file)
			{
				file = _file;
			}

			void redirect (std::string from, std::string to)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << code_blocks.redirect(from, to);
				nodejs.close();
			}

			void import (std::string pkg)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << code_blocks.import(pkg);
				nodejs.close();
			}

			void get (std::string _file)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << code_blocks.get(_file);
				nodejs.close();
			}

			void download (std::string _file)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << code_blocks.download(_file);
				nodejs.close();
			}

			void listen (int port)
			{
				nodejs.open(file, std::fstream::app);
				nodejs << code_blocks.listen(port);
				nodejs.close();
			}

	};

	class server
	{
		public:
			bool downloads;
			bool recursive;
			int port;
			std::string file;
			std::string index;
			std::string spaces;
			std::string downloads_folder;
			std::filesystem::path dir;
	};

}