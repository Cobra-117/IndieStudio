/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-adrien.michaud
** File description:
** map
*/

#include "../../include/Game/Map.hpp"
#include "../../include/Game/Tools/Utilities.hpp"
#include "../../include/indie.hpp"
#include <cmath>

Map::Map()
{
    _floorTile.init(FLOOR_WALL_TEX,
    FLOOR_WALL_MOD, Vector3  {0.0f, 5.0f, 0.0f },
    Vector3 { 1.0f, 0.0f, 0.0f }, Vector3 {0.5f, 0.5f, 0.5f });
    _Obstacle.init(BREAKABLE_WALL_TEX, BREAKABLE_WALL_MOD,
    Vector3  {0.0f, 5.0f, 0.0f },
    Vector3 { 1.0f, 0.0f, 0.0f }, Vector3 {0.5f, 0.5f, 0.5f });
    _Wall.init(UNBREAKABLE_WALL_TEX, UNBREAKABLE_WALL_MOD,
    Vector3  {0.0f, 5.0f, 0.0f },
    Vector3 { 1.0f, 0.0f, 0.0f }, Vector3 {0.5f, 0.5f, 0.5f });
    _Border.init(BORDER_WALL_TEX, BORDER_WALL_MOD,
    Vector3  {0.0f, 5.0f, 0.0f },
    Vector3 { 1.0f, 0.0f, 0.0f }, Vector3 {0.5f, 0.5f, 0.5f });

}

void Map::loadMapFromFile(std::string path)
{
    FileManager fm;
    std::string raw_map = fm.loadFileText(path);

    for (size_t i = 0; raw_map[i] != '\n' && raw_map[i] != '\0'; i++)
        _length += 1;
    _ascii_map = split_string(raw_map, "\n");
    _heigth = _ascii_map.size();
}

void Map::setAsciiTile(int x, int y, char c)
{
    if (y >= _heigth || x >= _length) {
        std::cerr << "Error: out of range" << std::endl;
        return;
    }
    _ascii_map[y][x] = c;
}

char Map::getAsciiTile(int x, int y)
{
    if (y >= _heigth || x >= _length) {
        std::cerr << "Error: out of range" << std::endl;
        return 0;
    }
    return(_ascii_map[y][x]);
}

bool Map::isBorderBlock(size_t x, size_t y)
{
    if ((y == 0 && x == 0) || (y == 1 && x == 0) || (y == 0 && x == 1))
        return true;
    if ((y == 0 && x == (size_t)(_length - 1)) || (y == 1 && x == (size_t)(_length - 1))
    || (y == 0 && x == (size_t)(_length - 2)))
        return true;
    if ((y == (size_t)(_heigth - 1) && x == 0) || (y == (size_t)(_heigth - 1) && x == 1)
    || (y == (size_t)(_heigth - 2) && x == 0))
        return true;
    if ((y == (size_t)(_heigth - 1) && x == (size_t)(_length - 1))
    || (y == (size_t)(_heigth - 2) && x == (size_t)(_length - 1))
    || (y == (size_t)(_heigth - 1) && x == (size_t)(_length - 2)))
        return true;
    return false;
}

void Map::generateRandomMap(int heigth, int length, int obstacle_frequency)
{
    int res = 0;

    _heigth = heigth;
    _length = length;
    for (size_t y = 0; y < heigth; y++) {
        _ascii_map.push_back("");
        _ascii_map[y].replace(0, length, length , '.');
        for (size_t x = 0; x < length; x++) {
            if (y % 2 == 1 && y < (heigth -1)
             && x % 2 == 1 && x < (length -1)) {
                _ascii_map[y][x] = '#';
            }
            else if (!isBorderBlock(x, y) && rand() % 100 < obstacle_frequency)
               _ascii_map[y][x] = 'x';
        }
    }
    YOffset = (float)round(_heigth / 2) + 2;
    XOffset = (float)round(_length / 2);
}

void Map::display()
{
    YOffset = (float)round(_heigth / 2) + 2;
    XOffset = (float)round(_length / 2);
    for (size_t y = 0; y < _heigth; y++) {
        for (size_t x = 0; x < _length; x++) {
            _floorTile.setPosition(Vector3{(float) x - XOffset, -1, (float) y - YOffset});
            _floorTile.IndieDrawEx(-90.0f, WHITE);
            if (_ascii_map[y][x] == '#') {
                _Wall.setPosition(Vector3{(float) x - XOffset, 0, (float) y - YOffset});
                _Wall.IndieDrawEx(-90.0f, WHITE);
            }
            if (_ascii_map[y][x] == 'x') {
                _Obstacle.setPosition(Vector3{(float) x - XOffset, 0, (float) y - YOffset});
                _Obstacle.IndieDrawEx(-90.0f, WHITE);
            }
        }
    }
    for (int y = -1; y <= _heigth; y++) {
        _Border.setPosition(Vector3{(float) -XOffset - 1, 0, (float) y - YOffset});
        _Border.IndieDrawEx(-90.0f, WHITE);
    }
    for (int y = -1; y <= _heigth; y++) {
        _Border.setPosition(Vector3{(float)_length -XOffset, 0, (float) y - YOffset});
        _Border.IndieDrawEx(-90.0f, WHITE);
    }
    for (int x = 0; x <= _length; x++) {
        _Border.setPosition(Vector3{(float)x - XOffset - 1, 0, (float) - YOffset - 1});
        _Border.IndieDrawEx(-90.0f, WHITE);
    }
    for (int x = 0; x <= _length; x++) {
        _Border.setPosition(Vector3{(float)x - XOffset - 1, 0, (float)_length - YOffset});
        _Border.IndieDrawEx(-90.0f, WHITE);
    }
}

void Map::flush()
{
    _ascii_map.clear();
}
