#include <iostream>
using namespace std;

#include "app.h"

int main(int argc, char** argv)
{
	app myApp;
	myApp.onExecute();

	cin.get();
	return 0;
}