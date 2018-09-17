
/***************************
*
File name:
gameEngine.cpp

Description:
added script for window check
***************************/
#include "checkStorage.h"
#include "windowCheck.h"
#include <iostream>

int main()
{
	CheckWindow windCheck;
	CheckStorage storCheck;

	windCheck.openWindow();
	storCheck.availableMemory();
	storCheck.availableStorage();
   

}
