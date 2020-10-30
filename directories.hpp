// directories.hpp
// Evan Overman
// Created Oct 29, 2020
// Last update: Oct 29, 2020

#include <string>
#include <filesystem>
 
struct path_leaf_string
{
    std::string operator()(const std::filesystem::directory_entry& entry) const
    {
        return entry.path().leaf().string();
    }
};
 
void read_directory(const std::string& name, stringvec& v)
{
    std::filesystem::path p(name);
    std::filesystem::directory_iterator start(p);
    std::filesystem::directory_iterator end;
    std::transform(start, end, std::back_inserter(v), path_leaf_string());
}