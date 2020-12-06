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
				void clear (void) // express::node server; server.open("server.js"); 
				{
					nodejs.clear();
					nodejs.close();
				}

				void open (std::filesystem::path _file)
				{
					file = _file;
				}

				void redirect (std::filesystem::path to, std::string from)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.redirect(to, from);
					nodejs.close();
				}

				void import (std::string pkg)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.import(pkg);
					nodejs.close();
				}

				void get (std::filesystem::path _file)
				{
					nodejs.open(file, std::fstream::app);
					nodejs << code_blocks.get(_file);
					nodejs.close();
				}

				void download (std::filesystem::path _file)
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

	}

    class js_file
	{
		private:
			express::code_blocks code_blocks;
			std::string file;
			std::fstream nodejs;

		public:
			void clear (void) // express::node server; server.open("server.js"); 
			{
				nodejs.clear();
				nodejs.close();
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
			std::filesystem::path dir;
	};

}