#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <fstream>

#include "command.h"

using namespace std;
using namespace std::filesystem;

int hexToDec(const std::string& hex)
{
    std::stringstream ss;
    ss << std::hex << hex;
    int dec;
    ss >> dec;
    return dec;
}

void createConfig(path configPath)
{
    if(!exists("config")) { create_directory("config"); }
    cout << configPath << endl;

    createFile(configPath.string());
}

string readConfig(path configPath)
{
    if(!exists(configPath))
        {
            createConfig(configPath);
            return "-1";
        }

    unordered_map<string, string> config = {{"colour", "#07f7f3"}};

    string ConfigText;
    string word;
    string configValue;
    bool trueFlag = false;

    fstream ConfigFile(configPath);
    while(getline(ConfigFile, ConfigText))
        {
            istringstream iss(ConfigText);

            while(iss >> word)
                {
                    if(word == "=") { continue; }

                    if(trueFlag)
                        {
                            config[configValue] = word;
                            trueFlag = false;
                            configValue = "";
                            cout<<word<<endl;
                            continue;
                        }

                    if(config.find(word) == config.end())
                        {
                            cout << word<< ": is not a valid parameter" << endl;
                            return "-1";
                        }
                    else
                        {
                            configValue = word;
                            trueFlag = true;
                        }
                }
        }


    int r = hexToDec(config["colour"].substr(1, 2));
    int g = hexToDec(config["colour"].substr(3, 2));
    int b = hexToDec(config["colour"].substr(5, 2));
    
    string colour = to_string(r)+";"+to_string(g)+";"+to_string(b)+"m";

    return colour;
}
