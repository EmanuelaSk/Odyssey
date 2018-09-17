#include "windowCheck.h"
#include <Windows.h>
#include <iostream>


using namespace std;



void CheckWindow::openWindow() 
{
	
	HWINSTA winLink = GetProcessWindowStation(); //gets handle to current window station
	
	if (winLink != NULL)
	{
		cout << "There is an instance of the window running" << endl <<endl;
	}
	else
	{
		cout << "there is no instance of the window running so techinically you shouldn't be able to see this message" << endl;
	}
}
