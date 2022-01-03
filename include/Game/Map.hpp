/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <vector>
#include <string>
#include "../Engine/Core/FileManager.hpp"
#include "../Engine/Models/models.hpp"

class Map
{
    public:
        Map();
        ~Map() {}
        std::vector<std::string> getMap() {return _ascii_map;}
        int getHeigth() {return _heigth;}
        int getLength() {return _length;}
        char getAsciiTile(int x, int y);
        void setAsciiTile(int x, int y, char c);
        void loadMapFromFile(std::string path);
        void generateRandomMap(int heigth, int length, int obstacle_frequency);
        void display();
        void map();
        void flush();
        bool isBorderBlock(size_t x, size_t y);
    public:
        IndieModel _floorTile;
        IndieModel _Obstacle;
        IndieModel _Wall;
        IndieModel _Border;
        std::vector<std::string> _ascii_map;
        int _heigth;
        int _length;
        float YOffset;
        float XOffset;
    private:
};

#endif /* !MAP_HPP_ */
