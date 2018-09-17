// gameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/***************************
*
File name:
gameEngine.cpp


Description:
Initial setup, configured debug build settings to
what was specified in week 1

***C/C++/Precompiled Header/ NOT USING PRECOMPILED HEADER ATM******

***************************/
#include "checkStorage.h"
#include "CPUSpeedDisplay.h"
#include "windowCheck.h"
#include <iostream>

int main()
{
	CheckWindow winCheck;
	CheckStorage storCheck;
	CPUStats cpuStat;

	winCheck.openWindow();
	storCheck.availableStorage();
	storCheck.availableMemory();
	cpuStat.PrintCPUStats();
   

}
