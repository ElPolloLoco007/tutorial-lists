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
	cd.createFolder();

	m.mainMenu();

	//rt.writeToFile();
	//rt.read_directory();
	return 0;
}