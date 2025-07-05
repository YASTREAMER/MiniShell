#include <iostream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

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
    if(dirs == "~")
        {
            current_path(getenv("HOME"));
            return;
        }
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
    if(!exists(dirs)) { create_directory(dirs); }
}

void removeDir(const path& dirs, string kwargs)
{
    if(kwargs != "-rf" && is_directory(dirs))
        {
            cout << "rm: cannot remove \'" << dirs.string()
                 << "\': is a directory"<<endl;
            return;
        }
    else if(kwargs == "-rf") { remove(dirs); }
    remove(dirs);
}

void clear() { system("clear"); }

void pwd() { cout << current_path().string() << endl; }
