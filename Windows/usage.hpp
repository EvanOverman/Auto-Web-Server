/*

Evan Overman
usage.hpp
Created 11/29/2020

*/

namespace usage
{
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
                       "/d, /downloads [bool]\t\tUse/dont use the downloads feature.\n"; 
            }

            const std::string recursive (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /r [string, path to directory]\n"; }
            const std::string non_recursive (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /n [string, path to directory]\n"; }
            const std::string port (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /p [int, port number]\n"; }
            const std::string file (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /f [string, file name]\n"; }
            const std::string downloads (const char *argv[]) { return "Usage: " + std::string(argv[0]) + " /d [boolean, true/false]\n"; }
    };

    struct errors
    {
        public:
            const std::string directory_does_not_exist (std::filesystem::path path) { return path.string() + " does not exist or is not a directory.\n"; }
            const std::string file_does_not_exist (std::filesystem::path file) { return file.string() + " does not exist or is not a file.\n"; }
            const std::string invalid_file_name (std::string file) { return file + " is not a valid file name.\n"; }
            const std::string no_value_given (std::string option) { return "No value given for option: " + option + ".\n"; }
    };

    struct prompts
    {
        public:
            const std::string file_already_exists (std::string file) { return file + " already exists, would you like to continue? [Y/n]: "; }
    };

}