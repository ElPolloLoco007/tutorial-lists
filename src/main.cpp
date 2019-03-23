
#include <iostream>

using namespace std;

#include "readTutorials.h"
#include "createDir.h"
#include "menu.h"

int main()
{
	Menu m;
	CreateDir cd;
	ReadTutorials rt;

	m.mainMenu();

	cd.createFolder();
	rt.writeToFile();
	rt.read_directory();
	return 0;
}