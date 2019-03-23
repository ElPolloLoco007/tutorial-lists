#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
using namespace std;

#ifndef READTUTORIALS_H
#define READTUTORIALS_H

class ReadTutorials
{
public:
  void writeToFile();
  void readFromFile(string tfile);
  void read_directory();

  ReadTutorials();
  ~ReadTutorials();

private:
  vector<string> v;
};
#endif
