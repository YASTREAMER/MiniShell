#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "command.h"
#include "parser.h"

using namespace std;
using namespace std::filesystem;

int main()
{
    string input;
    vector<string> parsedString;
    path dirs;
    string kwargs = "";

    // To display the Current directory
    string homeDir = getenv("HOME");
    string currentDir = current_path().string();
    if(currentDir.rfind(homeDir, 0) == 0)
        {
            currentDir = "~" + currentDir.substr(homeDir.length());
        }

    // Just to make the startup a bit clean
    clear();
    while(true)
        {
            cout << "\033[1;32m" << currentDir << "\033[0m $ ";
            getline(cin, input);
            if(input == "quit") { break; }
            parsedString = parse(input);

            if(parsedString.size() < 2) { dirs = ""; }
            else if(parsedString.size() < 3) { dirs = parsedString[1]; }
            else
                {
                    dirs = parsedString[2];
                    kwargs = parsedString[1];
                }

            if(parsedString[0] == "pwd") { pwd(); }
            else if(parsedString[0] == "clear") { clear(); }
            else if(parsedString[0] == "ls") { listDir(dirs); }
            else if(parsedString[0] == "mkdir") { mkdir(dirs); }
            else if(parsedString[0] == "rm") { removeDir(dirs, kwargs); }
            else if(parsedString[0] == "cd")
                {
                    cd(dirs);
                    currentDir = current_path();
                    if(currentDir.rfind(homeDir, 0) == 0)
                        {
                            currentDir =
                              "~" + currentDir.substr(homeDir.length());
                        }
                }
            else
                {
                    cout << "Command does not exits: \"" << parsedString[0]
                         << "\"" << endl;
                }
        }
}
