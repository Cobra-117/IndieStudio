/*
** EPITECH PROJECT, 2021
** sdfgh
** File description:
** jhgf
*/

#ifndef FILE_MANAGER
#define FILE_MANAGER

#include <string>

extern "C" {
    #include "raylib.h"
}

class FileManager
{
    private:
        std::string _fileContent;
    public:
        FileManager() = default;
        FileManager(std::string);
        ~FileManager() = default;
        unsigned char *loadFileData(const char *fileName, unsigned int *bytesRead);
        void unloadFileData(unsigned char *data);
        bool saveFileData(const char *fileName, void *data, unsigned int bytesToWrite);
        std::string loadFileText(std::string fileName);
        std::string getFileText(void);
        void unloadFileText(unsigned char *text);
        bool saveFileText(const char *fileName, char *text);
        bool fileExists(const char *fileName);
        bool directoryExists(const char *dirPath);
        bool isFileExtension(const char *fileName, const char *ext);
        const char *getFileExtension(const char *fileName);
        const char *getFileName(const char *filePath);
        const char *getFileNameWithoutExt(const char *filePath);
        const char *getDirectoryPath(const char *filePath);
        const char *getPrevDirectoryPath(const char *dirPath);
        const char *getWorkingDirectory(void);
        char **getDirectoryFiles(const char *dirPath, int *count);
        void clearDirectoryFiles(void);
        bool changeDirectory(const char *dir);
        bool isFileDropped(void);
        char **getDroppedFiles(int *count);
        void clearDroppedFiles(void);
        long getFileModTime(const char *fileName);
        unsigned char *compressData(unsigned char *data, int dataLength, int *compDataLength);
        unsigned char *decompressData(unsigned char *compData, int compDataLength, int *dataLength);
};

#endif
