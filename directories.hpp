// directories.hpp
// Evan Overman
// Created Oct 29, 2020
// Last update: Oct 29, 2020

#include <string>
#include <filesystem>

using namepace std;
 
struct path_leaf_string
{
    string operator()(const filesystem::directory_entry& entry) const
    {
        return entry.path().leaf().string();
    }
};
 
void read_directory(const string& name, stringvec& v)
{
    filesystem::path p(name);
    filesystem::directory_iterator start(p);
    filesystem::directory_iterator end;
    transform(start, end, back_inserter(v), path_leaf_string());
}