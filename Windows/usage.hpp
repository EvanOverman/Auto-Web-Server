/*

Evan Overman
usage.hpp
Created 11/29/2020

*/

namespace usage
{
    void usage (std::string executable = ".\\AutoWebServer.exe")
    {
        std::cout << std::endl;
        std::cout << "Usage: " << executable << " <option> <dir> [port]" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "/h, /help\t\t\tShow this help message." << std::endl;
        std::cout << "/i, /iterative\t\t\tMake the server using the iterative format." << std::endl;
        std::cout << "/n, /non-iterative\t\tMake the server using the non-iterative format." << std::endl;
        std::cout << std::endl;
    }

    void nonIterative (std::string executable = ".\\AutoWebServer.exe")
    {
        std::cout << "Uasge: " << executable << " /non-iterative <dir> <port>" << std::endl;
    }

    void iterative (std::string executable = ".\\AutoWebServer.exe")
    {
        std::cout << "Usage: " << executable << " /iterative <dir> <port>" << std::endl;
    }

    void homeFileDoesNotExist (void)
    {
        std::cout << "The given home file does not exist in the given directory." << std::endl;
    }

    struct help
    {
        public:
            const std::string man (const char *argv[])
            {
                return "Usage: " + std::string(argv[0]) + " <options>\n"
                       "Options:\n"
                       "/h, /help\t\t\tShow this help page.\n"
                       "/r, /recursive [string]\t\tMake a Node.js file using a recursive directory iterator.\n"
                       "/n, /non-recursive [string]\tMake a Node.js file using a non-recursive directory iterator.\n"
                       "/p, /port [int]\t\t\tStart the server on a different port than 80\n"
                       "/f, /file [string]\t\t\tSet the Node.js file to a different name that \"server.js\"\n"
                       "/d, /downloads [bool]\t\tUse/dont use the downloads feature."; 
            }

            const std::string recursive (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /r [string, path to directory]"; }
            const std::string non_recursive (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /n [string, path to directory]"; }
            const std::string port (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /p [int, port number]"; }
            const std::string file (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /f [string, file name]"; }
            const std::string downloads (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /d [boolean, true/false]"; }
    };

    struct errors
    {
        public:
            const std::string directory_does_not_exist (std::filesystem::path path) { return path.string() + " does not exist or is not a directory."; }
            const std::string file_does_not_exist (std::filesystem::path file) { return file.string() + " does not exist or is not a file."; }
    };

}