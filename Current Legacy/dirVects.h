// dirVects.h
// Evan Overman
// Created Nov 27, 2020

namespace dir
{
    std::vector <std::string> listDir(const char *path)
    {
        std::string list;
        struct dirent *entry;
        DIR *dir = opendir(path);

        if (dir == nullptr) // Check if dir is empty.
        {
            return splitString(list, '\n');
        }

        while ((entry = readdir(dir)) != nullptr)
        {
            list += entry -> d_name + '\n'; // Add each file seperated by a new line.
        }

        closedir(dir);
        return splitString(list, '\n');
    }
}