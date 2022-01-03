/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** directoryReader
*/

#include "../../../include/Game/Tools/DirectoryReader.hpp"

DirectoryReader::DirectoryReader(std::string p)
{
    if (!std::filesystem::exists(p)) {
        exit(84);
    }
    dir = p;
}

DirectoryReader::~DirectoryReader(void)
= default;

std::vector<std::string> DirectoryReader::getFiles(void) const
{
    std::vector<std::string> files;

    for (auto & entry : std::filesystem::directory_iterator(dir)) {
        files.push_back(entry.path().filename().u8string());
    }
    return files;
}

/*DirectoryReader::DirectoryReader(std::string p)
{
    dir = opendir(p.c_str());
    if (dir == NULL) {
        exit(84);
    }
}

DirectoryReader::~DirectoryReader(void)
{
    closedir(dir);
}

std::vector<std::string> DirectoryReader::getFiles(void) const
{
    std::vector<std::string> files;
    struct dirent *ent;

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            if (ent->d_name)
                files.push_back(ent->d_name);
        }
    }
    return files;
}*/