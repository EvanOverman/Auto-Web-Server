/*

Evan Overman
usage.hpp
Created 11/29/2020

*/

namespace usage
{
    void usage (std::string executable = "./AutoWebServer")
    {
        std::cout << std::endl;
        std::cout << "Usage: " << executable << " <option> <dir> [port]" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "\t-h, --help\t\t\tShow this help message." << std::endl;
        std::cout << "\t-i, --iterative\t\t\tMake the server using the iterative format." << std::endl;
        std::cout << "\t-n, --non-iterative\t\tMake the server using the non-iterative format." << std::endl;
        std::cout << std::endl;
    }

    void nonIterative (std::string executable = "./AutoWebServer")
    {
        std::cout << "Uasge: " << executable << " /non-iterative <dir> <port>" << std::endl;
    }

    void iterative (std::string executable = "./AutoWebServer")
    {
        std::cout << "Usage: " << executable << " /iterative <dir> <port>" << std::endl;
    }

    void homeFileDoesNotExist (void)
    {
        std::cout << "The given home file does not exist in the given directory." << std::endl;
    }

}