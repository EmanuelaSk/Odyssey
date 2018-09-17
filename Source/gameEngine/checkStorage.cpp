/***************************
Lab 2

File name:
checkStorage.cpp

Description:
Check for 300MB of available storage
Check for memory and display how much virtual & ram is available

Storage = Disk Drive of Solid State
Memory  = RAM or virtual memory

***************************/

#include "checkStorage.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

void CheckStorage::availableStorage()
{
	ULARGE_INTEGER freeSpace;
	bool storeResult  = GetDiskFreeSpaceEx(NULL, &freeSpace,NULL,NULL);
	
	unsigned long long amount = freeSpace.QuadPart; //converting to compare against minAvailStorage
	minAvailStorage = 30000; //storage in bytes
	if (amount > minAvailStorage) { //check for storage

		cout << "Storage Available" << endl << endl;
		}
	else if (amount < minAvailStorage)
	{
		cout << "ERROR: Not enough storage" << endl <<endl;
	}

}

void CheckStorage::availableMemory()
{
	MEMORYSTATUSEX memory; 	//use MEMORYSTATUSEX instead MEMORYSTATUS for computers with more than 4g of memory
	
	memory.dwLength = sizeof(memory);
	GlobalMemoryStatusEx(&memory);
	unsigned long long virtMem = memory.ullAvailVirtual;
	unsigned long long physMem = memory.ullAvailPhys;
	minAvailStorage = 6000000000000000000;
	//check for available memory
	if (minAvailStorage > virtMem && physMem) {
		cout << "ERROR: not enough available memory" << endl << endl;
	}
	else
	{
		cout << "memory available" << endl << endl;
	}

	//checking for available storage in bytes
	cout << "Amount of VIRTUAL MEMORY available: " << memory.ullAvailVirtual /(1024*1024)<<" MB"<< endl;
	cout << "Amount of RAM available: " << memory.ullAvailPhys /(1024*1024) <<" MB"<< endl <<endl;

}

