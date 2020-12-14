/*

Evan Overman
usage.hpp
Created 11/29/2020

*/

namespace usage
{
    const std::string args[14] = 
    {
        "/h", "/help", 
        "/D", "/directory",
        "/r", "/recursive", 
        "/p", "/port",
        "/f", "/file",
        "/i", "/index",
        "/d", "/downloads"
    };
 
    struct help
    {
        public:
            const std::string man (const char *argv[])
            {
                return "Usage: " + std::string(argv[0]) + " <options>\n"
                       "Options:\n"
                       "/h, /help\t\t\tShow this help page.\n"
                       "/D, /directory [string]\t\tSet a different directory to make the Node.js file from.\n"
                       "/r, /recursive [bool]\t\tScan directory using the recursive directory iterator.\n"
                       "/p, /port [int]\t\t\tStart the server on a different port than 80.\n"
                       "/f, /file [string]\t\tSet the Node.js file to a different name than \"server.js\".\n"
                       "/i, /index [string]\t\tSet the name for your homepage file, so that it is hosted at root.\n"
                       "/d, /downloads [bool/string]\tUse/dont use the downloads feature and specify a folder name.\n"; 
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
            const std::string directory_does_not_exist (const std::filesystem::path path) { return path.string() + " does not exist or is not a directory.\n"; }
            const std::string file_does_not_exist (const std::filesystem::path file) { return file.string() + " does not exist or is not a file.\n"; }
            const std::string invalid_file_name (const std::string name) { return name + " is not a valid file name.\n"; }
            const std::string invalid_port (const std::string port) { return port + " is not a valid port number.\n"; }
            const std::string non_bool_given (const std::string value) { return value + " is not a valid boolean value (true/false).\n"; }
            const std::string no_value_given (const std::string option) { return "No value given for option: " + option + ".\n"; }
    };

    struct prompts
    {
        public:
            const std::string file_already_exists (const std::string file) { return file + " already exists, would you like to continue? [Y/n]: "; }
    };

}