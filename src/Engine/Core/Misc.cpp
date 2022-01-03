/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** jhgfd
*/

#include "../../../include/Exceptions.hpp"
#include "../../../include/Engine/Core/Misc.hpp"
#include "../../../include/Game/Tools/DirectoryReader.hpp"

int Misc::getRandomValue(int min, int max)
{
    return GetRandomValue(min, max);
}

void Misc::takeScreenshot(std::string fileName)
{
    TakeScreenshot(fileName.c_str());
}

void Misc::CheckScreenShotToTake(void)
{
    if (IsKeyPressed(KEY_N)) {
        DirectoryReader reader(SCREENSHOT_PATH);
        std::vector<std::string> list = reader.getFiles();

        takeScreenshot(SCREENSHOT_PATH"ScreenShot" + std::to_string(list.size() + 1) + EXTENSION_SCREENSHOT);
    }
}

void *Misc::memAlloc(int size)
{
    return MemAlloc(size);
}

void *Misc::memRealloc(void *ptr, int size)
{
    return MemRealloc(ptr, size);
}

void Misc::memFree(void *ptr)
{
    MemFree(ptr);
}