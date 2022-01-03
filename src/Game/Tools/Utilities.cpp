/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** utilities
*/

#include <vector>
#include <string>

std::string removeExtension(std::string str)
{
    size_t lastindex = str.find_last_of("."); 
    std::string rawname = str.substr(0, lastindex);
    return rawname;
}

std::vector<std::string> split_string(std::string str, std::string token)
{
    std::vector<std::string> result;

    while (str.size()) {
        int index = str.find(token);
        if (index != std::string::npos){
            result.push_back(str.substr(0, index));
            str = str.substr(index+token.size());
            if (str.size() == 0)
                result.push_back(str);
        } else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
