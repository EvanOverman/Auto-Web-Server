/*

Evan Overman
files.hpp
Created 12/02/2020

*/

namespace files
{
    std::vector <std::string> non_recursive (std::filesystem::path dir)
    {
        std::vector <std::string> files;

        for (std::filesystem::path path: std::filesystem::directory_iterator(dir))
        {
            if (!std::filesystem::is_directory(path))
            {
                std::string _path = path.relative_path().string();

                if (_path[0] == '.')
                {
                    _path.erase(0, 1);
                }

                std::replace(_path.begin(), _path.end(), '\\', '/');
                files.push_back(_path);
            }

        }

        return files;

    }

    std::vector <std::string> recursive (std::filesystem::path dir)
    {
        std::vector <std::string> files;

        for (std::filesystem::path path: std::filesystem::recursive_directory_iterator(dir))
        {
            if (!std::filesystem::is_directory(path))
            {
                std::string _path = path.relative_path().string();

                if (_path[0] == '.')
                {
                    _path.erase(0, 1);
                }

                std::replace(_path.begin(), _path.end(), '\\', '/');
                files.push_back(_path);
            }

        }

        return files;

    }
    
}