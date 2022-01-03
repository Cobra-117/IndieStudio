/*
** EPITECH PROJECT, 2021
** sdfghjk
** File description:
** kjhgf
*/

#include "../../../include/Exceptions.hpp"
#include "../../../include/Engine/Core/FileManager.hpp"
#include <sys/types.h>
#include <sys/stat.h>

FileManager::FileManager(std::string str)
{
    _fileContent = std::string(LoadFileText(str.c_str()));
}

unsigned char *FileManager::loadFileData(const char *fileName, unsigned int *bytesRead)
{
    struct stat sb;
    if (stat(fileName, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return LoadFileData(fileName, bytesRead);
}

void FileManager::unloadFileData(unsigned char *data)
{
    UnloadFileData(data);
}

bool FileManager::saveFileData(const char *fileName, void *data, unsigned int bytesToWrite)
{
    struct stat sb;
    if (stat(fileName, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return SaveFileData(fileName, data, bytesToWrite);
}

std::string FileManager::loadFileText(std::string fileName)
{
    struct stat sb;
    if (stat(fileName.c_str(), &sb) == -1)
        throw Exceptions("Inexisting file.");
    const char *a = fileName.c_str();
    return std::string(LoadFileText(a));
}

std::string FileManager::getFileText(void)
{
    return _fileContent;
}

// void FileManager::unloadFileText(unsigned char *text)
// {
//     UnloadFileText(text);
// }

bool FileManager::saveFileText(const char *fileName, char *text)
{
    struct stat sb;
    if (stat(fileName, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return SaveFileText(fileName, text);
}

bool FileManager::fileExists(const char *fileName)
{
    return FileExists(fileName);
}

bool FileManager::directoryExists(const char *dirPath)
{
    return DirectoryExists(dirPath);
}

bool FileManager::isFileExtension(const char *fileName, const char *ext)
{
    struct stat sb;
    if (stat(fileName, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return IsFileExtension(fileName, ext);
}

const char *FileManager::getFileExtension(const char *fileName)
{
    struct stat sb;
    if (stat(fileName, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return GetFileExtension(fileName);
}

const char *FileManager::getFileName(const char *filePath)
{
    struct stat sb;
    if (stat(filePath, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return GetFileName(filePath);
}

const char *FileManager::getFileNameWithoutExt(const char *filePath)
{
    struct stat sb;
    if (stat(filePath, &sb) == -1)
        throw Exceptions("Inexisting file.");
    return GetFileNameWithoutExt(filePath);
}

const char *FileManager::getDirectoryPath(const char *filePath)
{
    return GetDirectoryPath(filePath);
}

const char *FileManager::getPrevDirectoryPath(const char *dirPath)
{
    return GetPrevDirectoryPath(dirPath);
}

const char *FileManager::getWorkingDirectory(void)
{
    return GetWorkingDirectory();
}

char **FileManager::getDirectoryFiles(const char *dirPath, int *count)
{
    return GetDirectoryFiles(dirPath, count);
}

void FileManager::clearDirectoryFiles(void)
{
    ClearDirectoryFiles();
}

bool FileManager::changeDirectory(const char *dir)
{
    return ChangeDirectory(dir);
}

bool FileManager::isFileDropped(void)
{
    return IsFileDropped();
}

char **FileManager::getDroppedFiles(int *count)
{
    return GetDroppedFiles(count);
}

void FileManager::clearDroppedFiles(void)
{
    ClearDroppedFiles();
}

long FileManager::getFileModTime(const char *fileName)
{
    return GetFileModTime(fileName);
}

unsigned char *FileManager::compressData(unsigned char *data, int dataLength, int *compDataLength)
{
    return CompressData(data, dataLength, compDataLength);
}

unsigned char *FileManager::decompressData(unsigned char *compData, int compDataLength, int *dataLength)
{
    return DecompressData(compData, compDataLength, dataLength);
}
