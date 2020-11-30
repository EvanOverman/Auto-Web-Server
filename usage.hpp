/*

Evan Overman
usage.hpp
Created 11/29/2020

*/

namespace usage
{
    void usage (std::string executable = "./AutoWebServer")
    {
        std::cout << "Usage: " << executable << " <option> <dir> [port] [home]" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "\t-h, --help\t\t\t\tShow this help message." << std::endl;
        std::cout << "\t-o, --iterative\t\tStart server using the iterative format." << std::endl;
        std::cout << "\t-s, --simple [port, int]\t\t\tStart server using simple format." << std::endl;
        std::cout << "\t-p, --prompt\t\t\t\tUse the program with prompts instead of arguments." << std::endl;

        std::cout << std::endl;
        std::cout << "Sub-Options:" << std::endl;
        std::cout << "\t[system]\t\t\t\t(debian, deb, ubuntu)" << std::endl;
        std::cout << "\t[port]\t\t\t\t\tInteger, i.e. 80" << std::endl;
    }

    void nonIterative (std::string executable = "./AutoWebServer")
    {
        std::cout << "Uasge: " << executable << " --non-iterative <dir> <port>" << std::endl;
    }

    void iterative (std::string executable = "./AutoWebServer")
    {
        std::cout << "Usage: " << executable << " --iterative <dir> <port>" << std::endl;
    }

    void homeFileDoesNotExist (void)
    {
        std::cout << "The given home file does not exist in the given directory." << std::endl;
    }

}