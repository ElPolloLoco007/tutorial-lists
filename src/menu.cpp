#include "menu.h"

Menu::Menu() {}

Menu::~Menu() {}

void Menu::setMenuOption(int option) { menuOption = option; }

void Menu::doMenuOption() {

  cout << endl << "Make your option:";
  int option;
  // checking if its a integer that is pressed, and removing the wrongfully
  // letter
  while (!(cin >> option) || option >= vTxtFiles.size()) {
    cin.clear();
    while (cin.get() != '\n')
      continue;

    printMenu();

    // reporting that the user has used wrong input
    cout << printBottomLine() << endl;
    cout << "Invalid number!" << endl;
    cout << "Please enter a valid number from the list:";
  }
  setMenuOption(option);
}
void Menu::menuOptions() {
  string c = "/Documents/TList/";
  string str = getenv("HOME") + c;
  char *cstr = &str[0u];
  DIR *pDIR;
  struct dirent *entry;
  if (pDIR = opendir(cstr)) {
    while (entry = readdir(pDIR)) {

      int i;
      for (i = 0; entry->d_name[i] != '\0'; i++) {
      }

      if (entry->d_name[i - 4] == '\056') {
        vTxtFiles.push_back(entry->d_name);
      } else {
        vFolders.push_back(entry->d_name);
      }
    }

    // Removing from vector
    //--------------
    auto itr = find(vFolders.begin(), vFolders.end(), "..");
    if (itr != vFolders.end())
      vFolders.erase(itr);

    auto itr2 = find(vFolders.begin(), vFolders.end(), ".");
    if (itr2 != vFolders.end())
      vFolders.erase(itr2);
    //--------------

    vFiles.reserve(vFolders.size() + vTxtFiles.size()); // preallocate memory
    vFiles.insert(vFiles.end(), vFolders.begin(), vFolders.end());
    vFiles.insert(vFiles.end(), vTxtFiles.begin(), vTxtFiles.end());
  }
  closedir(pDIR);

}

void Menu::mainMenu() {
  menuOptions();

  bool again = true;
  do {
    printMenu();

    doMenuOption(); // Setting the menu choice from the user
    cout << endl << printTopLine(vFiles.at(getMenuOption())) << endl;

    rt->readFromFile(vTxtFiles.at(getMenuOption()));
    returnToMenu();
  }

  while (again);
}

void Menu::printMenu() {
  cout << "**Tutorial Lists**"
       << "\n";

  int x = 0;
  for (auto i : vFiles) {
    if (x < vFolders.size()) {
      std::cout << x << ".- " << i << "\n";
      x++;
    } else {
      std::cout << x << "." << i << "\n";
      x++;
    }
  }
}

void Menu::returnToMenu() {
  cout << endl << printBottomLine() << endl;
  cout << "Press Enter to return to menu:";
  cin.get();
  cin.get();
}

string Menu::printTopLine(string x) {
  int tmp = x.length();
  int y = 40;
  int t = (y - tmp) / 2;
  string cool;

  for (int i = 0; i < t; i++) {
    cool += "-";
  }
  cool += x;
  for (int i = 0; i < t; i++) {
    cool += "-";
  }
  return cool;
}
string Menu::printBottomLine() {
  string cool;
  for (int i = 0; i < 40; i++) {
    cool += "-";
  }

  return cool;
}