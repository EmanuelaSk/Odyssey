//Display CPU speed & architecture
#include "CPUSpeedDisplay.h"

void CPUStats::PrintCPUStats()
{
	DWORD BufSize = _MAX_PATH;
	DWORD dwMHz = _MAX_PATH;
	HKEY hKey;
	
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		L"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",0,KEY_READ,&hKey);

	if (lError != ERROR_SUCCESS)
	{// if the key is not found, tell the user why:
		cout << "No KEY Found" << endl;
	}
	else
	{
		// query the key:
		RegQueryValueEx(hKey, L"~MHz", NULL, NULL, (LPBYTE)&dwMHz, &BufSize);//speed of cpu
		cout << "Speed of CPU: " << dwMHz << endl;
	}

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
	{
		cout << sysInfo.wProcessorArchitecture << ": Means x64 (AMD or Intel) Architecture" << endl;
	}
	else if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM)
	{
		cout << sysInfo.wProcessorArchitecture << ": Means ARM Architecture" << endl;
	}
	else if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM64)
	{
		cout << sysInfo.wProcessorArchitecture << ": Means ARM64 Architecture" << endl;
	}
	else if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_IA64)
	{
		cout << sysInfo.wProcessorArchitecture << ": Means Intel Itanium-based Architecture" << endl;
	}
	else if (sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
	{
		cout << sysInfo.wProcessorArchitecture << ": Means x86 Architecture" << endl;
	}
	else
	{
		cout << sysInfo.wProcessorArchitecture << ": Means Unknown Architecture" << endl;
	}
}