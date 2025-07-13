#include <filesystem>
#include <string>
#include <vector>

#ifndef command_H
#define command_H

void pwd();
void clear();
std::string Handle_Home(std::string dirs);
void cd(std::filesystem::path dirs = "");
void createFile(const std::string& fileName);
void mkdir(const std::filesystem::path& dirs);
void listDir(std::filesystem::path dirs = "");
void echo(const std::string& dirs, const std::string& kwargs = "");
void removeDir(const std::filesystem::path& dirs, std::string kwargs = "");

#endif
