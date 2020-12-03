/*

Evan Overman


*/
namespace node
{
    struct server
	{
		public:
			bool downloads;
			bool recursive;
			int port;
			std::string file;
			std::filesystem::path dir;
	};

    class js_file
	{
		private:
			express::code_blocks code_blocks;
			std::string file;
			std::fstream nodejs;

		public:

			void clear () // express::node server; server.open("server.js"); 
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

			void listen (std::string port = "80")
			{
				nodejs.open(file, std::fstream::app);
				nodejs << code_blocks.listen(port);
				nodejs.close();
			}

	};

}