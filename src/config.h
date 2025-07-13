#include <filesystem>
#include <string>

#ifndef CONIFG_H
#define CONIFG_H

int hexToDec(const std::string& hex);
void createConfig(std::filesystem::path configPath = "config/.config");
std::string readConfig(std::filesystem::path configPath = "config/.config");

#endif
