/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** directoryReader
*/

#ifndef DIRECTORYREADER_HPP_
#define DIRECTORYREADER_HPP_

//#include <dirent.h>
#include <vector>
#include <iostream>
#include <filesystem>
#include <string>

class DirectoryReader {
    public:
        DirectoryReader(std::string);
        ~DirectoryReader();
        std::vector<std::string> getFiles(void) const;
    private:
        std::string dir;
};

/*class DirectoryReader {
    public:
        DirectoryReader(std::string);
        ~DirectoryReader();
        std::vector<std::string> getFiles(void) const;
    private:
        DIR *dir;
};*/

#endif /* !DIRECTORYREADER_HPP_ */