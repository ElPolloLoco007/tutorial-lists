#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#include <memory>
#include <algorithm>

#include "readTutorials.h"

using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu
{
private:
  vector<string> vMenuOptions;
  int menuOption;
  shared_ptr<ReadTutorials> rt;

public:
  Menu();
  ~Menu();
  void doMenuOption();
  void menuOptions();
  void mainMenu();
  void setMenuOption(int option);
  int getMenuOption() { return menuOption; };
  void clearScreen();
  void printMenu();
  void returnToMenu();
};
#endif
