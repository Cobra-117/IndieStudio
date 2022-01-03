/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by flavien,
*/

#include "Test.hpp"
#include "raylib.h"

int stringEqual(std::string one, std::string two)
{
    if (one == two)
        return 0;
    else
        return 1;
}

int listStringEqual(std::vector<std::string> list, std::string find)
{
    for (auto &x : list) {
        if (x == find)
            return 0;
    }
    return 1;
}

void testWindow(MainMenu menu)
{
    assert(menu.MenuWindow() == 0);
}

void testUtility()
{
    //test 0
    DirectoryReader reader(".");
    assert(listStringEqual(reader.getFiles(), "bomberman") == 0);

    //test 1
    std::vector<std::string> testVectorSplit = split_string("Hello World", " ");
    assert(stringEqual(testVectorSplit.back(), "World") == 0);

    //test 2
    assert(stringEqual(removeExtension("Hello.word"), "Hello") == 0);
}

int main(int, char**)
{
    //test 0 1 2
    testUtility();

    //test 3
    // testWindow(MainMenu());
}