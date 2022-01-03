/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** utilities
*/

#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include <vector>
#include <string>

std::vector<std::string> split_string(std::string str, std::string token);
std::vector<std::string> SortVector(std::vector<std::string> list);
std::string removeExtension(std::string str);

#endif /* !UTILITIES_HPP_ */
