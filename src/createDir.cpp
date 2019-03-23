#include "createDir.h"

CreateDir::CreateDir()
{
    homepath = getenv("HOME");
    place = "/Documents/TList";
    destination = homepath + place;
}

CreateDir::~CreateDir()
{
    //delete dp;
}

void CreateDir::createFolder()
{
    const char *c = destination.c_str();

    // Creating a directory
    if (mkdir(c, 0777) == -1)
        cerr << "Error :  " << strerror(errno) << endl;

    else
    {
        cout << "Directory created";
    }
}