// C++ program to create a directory in Linux
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
using namespace std;

#ifndef CREATEDIR_H
#define CREATEDIR_H

class CreateDir
{
public:
  void createFolder();  

  CreateDir();
  ~CreateDir();

private:
	string homepath;
	string place;
	string destination;
  
};
#endif