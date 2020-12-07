/*

Evan Overman
files.hpp
Created 12/02/2020

*/

namespace files
{
    namespace paths
    {
        std::vector <std::filesystem::path> non_recursive (std::filesystem::path dir)
        {
            std::vector <std::filesystem::path> files;

            for (std::filesystem::path path: std::filesystem::directory_iterator(dir))
            {
                if (!std::filesystem::is_directory(path))
                {
                    files.push_back(path);
                }

            }

            return files;

        }

        std::vector <std::filesystem::path> recursive (std::filesystem::path dir)
        {
            std::vector <std::filesystem::path> files;

            for (std::filesystem::path path: std::filesystem::recursive_directory_iterator(dir))
            {
                if (!std::filesystem::is_directory(path))
                {
                    files.push_back(path);
                }
                
            }

            return files;

        }

    }

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

    std::string replace (std::string file, const std::string from, const std::string to) 
    {
        int start_pos = 0;

        while ((start_pos = file.find(from, start_pos)) != std::string::npos) 
        {
            file.replace(start_pos, from.length(), to);
            start_pos += to.length();

        }

        return file;
    }

    std::string remove_dir (std::string file, const std::string dir)
    {
        size_t position = std::string::npos;

        while ((position = file.find(dir)) != std::string::npos)
        {
            file.erase(position, dir.length());
        }

        while (true)
        {
            if (file[0] == '/')
            {
                file.erase(0, 1);
            }

            else
            {
                break;
            }
            
        }

        return file;

    }
    
}