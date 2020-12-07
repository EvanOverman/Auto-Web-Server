/*

Evan Overman
usage.hpp
Created 11/29/2020

*/

namespace usage
{
    const std::string args[16] = 
    {
        "-h", "--help", 
        "-D", "--directory",
        "-s", "--spaces",
        "-r", "--recursive", 
        "-p", "--port",
        "-f", "--file",
        "-i", "--index",
        "-d", "--downloads"
    };
 
    struct help
    {
        public:
            const std::string man (char *argv[])
            {
                return "Usage: " + std::string(argv[0]) + " <options>\n\n"
                       "Options:\n"
                       "-h, --help\t\t\tShow this help page.\n"
                       "-D, --directory [string]\tSet a different directory to make the Node.js file from.\n"
                       "-r, --recursive [bool]\t\tScan directory using the recursive directory iterator.\n"
                       "-p, --port [int]\t\tStart the server on a different port than 80.\n"
                       "-s, --spaces [string]\t\tSet what spaces in file names are replaced with.\n"
                       "-f, --file [string]\t\tSet the Node.js file to a different name that \"server.js\".\n"
                       "-i, --index [string]\t\tSet the name for your homepage file, so that it is hosted at root.\n"
                       "-d, --downloads [bool/string]\tUse/dont use the downloads feature and specify a folder name.\n\n"; 
            }

            const std::string recursive (char *argv[]) { return "Usage: " + std::string(argv[0]) + " -r [string, path to directory]\n"; }
            const std::string non_recursive (char *argv[]) { return "Usage: " + std::string(argv[0]) + " -n [string, path to directory]\n"; }
            const std::string port (char *argv[]) { return "Usage: " + std::string(argv[0]) + " -p [int, port number]\n"; }
            const std::string file (char *argv[]) { return "Usage: " + std::string(argv[0]) + " -f [string, file name]\n"; }
            const std::string downloads (char *argv[]) { return "Usage: " + std::string(argv[0]) + " -d [boolean, true/false]\n"; }
    };

    struct errors
    {
        public:
            const std::string directory_does_not_exist (std::filesystem::path path) { return path.string() + " does not exist or is not a directory.\n"; }
            const std::string file_does_not_exist (std::filesystem::path file) { return file.string() + " does not exist or is not a file.\n"; }
            const std::string invalid_file_name (std::string name) { return name + " is not a valid file name.\n"; }
            const std::string invalid_port (std::string port) { return port + " is not a valid port number.\n"; }
            const std::string non_bool_given (std::string value) { return value + " is not a valid boolean value (true/false).\n"; }
            const std::string no_value_given (std::string option) { return "No value given for option: " + option + ".\n"; }
    };

    struct prompts
    {
        public:
            const std::string file_already_exists (std::string file) { return file + " already exists, would you like to continue? [Y/n]: "; }
    };

}