#include "menu.h"

Menu::Menu() {}

Menu::~Menu()
{
}

void Menu::setMenuOption(int option)
{
    menuOption = option;
}

void Menu::doMenuOption()
{

    cout << endl
         << "Make your option:";
    int option;
    //checking if its a integer that is pressed, and removing the wrongfully letter
    while (!(cin >> option) || option >= vMenuOptions.size())
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;

        printMenu();

        //reporting that the user has used wrong input
        cout << "Invalid number!" << endl;
        cout << "Please enter a valid number from the list:";
    }

    setMenuOption(option);
}
void Menu::menuOptions()
{
    string c = "/Documents/TList/";
    string str = getenv("HOME") + c;
    char *cstr = &str[0u];
    DIR *pDIR;
    struct dirent *entry;
    if (pDIR = opendir(cstr))
    {
        while (entry = readdir(pDIR))
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
                //string tmp = entry->d_name.substr (0,entry->d_name.length()-1);
                vMenuOptions.push_back(entry->d_name);
        }
        closedir(pDIR);

        free(cstr);
    }
}

void Menu::mainMenu()
{
    menuOptions();

    //Removing from vector
    //--------------
    auto itr = find(vMenuOptions.begin(), vMenuOptions.end(), "..");
    if (itr != vMenuOptions.end())
        vMenuOptions.erase(itr);

    auto itr2 = find(vMenuOptions.begin(), vMenuOptions.end(), ".");
    if (itr2 != vMenuOptions.end())
        vMenuOptions.erase(itr2);
    //--------------

    bool again = true;
    do
    {
        printMenu();

        doMenuOption(); // Setting the menu choice from the user

        rt->readFromFile(vMenuOptions.at(getMenuOption()));
        returnToMenu();
    }

    while (again);
}

void Menu::clearScreen()
{
    //Clearing the screen with empty lines
    int n;
    for (n = 0; n < 10; n++)
        cout << ("\n\n\n\n\n\n\n\n\n\n");
}

void Menu::printMenu()
{
    cout
        << "**Menu**"
        << "\n";

    int x = 0;

    for (auto i : vMenuOptions)
    {
        std::cout << x << "." << i << "\n";
        x++;
    }
}

void Menu::returnToMenu()
{
    cout << endl
         << "------------------------------" << endl;
    cout << "Press Enter to return to menu:";
    cin.get();
    cin.get();
}