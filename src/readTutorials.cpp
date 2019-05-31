

#include "readTutorials.h"

ReadTutorials::ReadTutorials() {}

ReadTutorials::~ReadTutorials() {
  // delete dp;
}

void ReadTutorials::writeToFile() {
  string homepath = getenv("HOME");
  ofstream tFile;
  tFile.open(homepath + "/Documents/tests/test.txt");
  tFile << "Writing this to a file again.\n";
  tFile << "cool bro.\n";
  tFile.close();
}

void ReadTutorials::readFromFile(string tfile) {
  string homepath = getenv("HOME");
  string line;
  ifstream tFile(homepath + "/Documents/TList/" + tfile);
  if (tFile.is_open()) {
    while (getline(tFile, line)) {
      cout << line << '\n';
    }
    tFile.close();
  } else {
    cout << "Unable to open file WTF asdas";
  }
}

void ReadTutorials::read_directory() {
  string c = "/Documents/tests/";
  string str = getenv("HOME") + c;
  char *cstr = &str[0u];
  DIR *pDIR;
  struct dirent *entry;
  if (pDIR = opendir(cstr)) {
    while (entry = readdir(pDIR)) {
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        cout << entry->d_name << "\n";
      v.push_back(entry->d_name);
    }
    closedir(pDIR);
    cout << v.size();

    free(cstr);
  }
}