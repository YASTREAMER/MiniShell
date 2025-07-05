#include <string>
#include <vector>
#include <filesystem>

#ifndef command_H
#define command_H

void listDir(std::filesystem::path dirs);
void cd(std::filesystem::path dirs);
void clear();
void mkdir(const std::filesystem::path& dirs);
void removeDir(const std::filesystem::path& dirs, std::string kwargs ="");
void pwd();

#endif
