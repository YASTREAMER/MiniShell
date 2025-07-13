#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::filesystem;

void clear() { system("clear"); }

void pwd() { cout << current_path().string() << endl; }

string Handle_Home(string dirs)
{
    size_t pos = dirs.find('~');
    if(pos != string::npos) { dirs.replace(pos, 1, getenv("HOME")); }
    return dirs;
}

void listDir(path dirs)
{
    if(dirs.empty()) { dirs = current_path(); }
    if(!exists(dirs))
        {
            cout << "ls: cannot access " << dirs
                 << ": No such file or directory " << endl;
            return;
        }

    for(auto dir : directory_iterator(dirs))
        {
            if(dir.is_directory())
                {
                    cout << dir.path().filename().string() << "/" << "\t";
                }
            else { cout << dir.path().filename().string() << "\t"; }
        }
    cout << endl;
}

void cd(path dirs)
{
    if(dirs.empty()) { return; }

    if(!exists(dirs))
        {
            cout << "cd: cannot change directory " << dirs
                 << " directory does not exits " << endl;
            return;
        }
    current_path(dirs);
}

void mkdir(const path& dirs)
{
    if(!exists(dirs) && !dirs.empty()) { create_directory(dirs); }
}

void removeDir(const path& dirs, string kwargs)
{
    if(kwargs != "-rf" && is_directory(dirs))
        {
            cout << "rm: cannot remove \'" << dirs.string()
                 << "\': is a directory" << endl;
            return;
        }
    else if(kwargs == "-rf") { remove_all(dirs); }
    remove(dirs);
}

void echo(const string& dirs, const string& kwargs)
{
    if(kwargs == "-n") { cout << dirs; }
    else
        {
            cout << dirs << endl;
            cout << endl;
        }
}

void createFile(const string& fileName)
{
    path filename = fileName;

    if(!exists(fileName))
        {
            ofstream MyFile(fileName);
            if(!MyFile) { cout << "File creation failed" << endl; }
            MyFile.close();
        }
}
