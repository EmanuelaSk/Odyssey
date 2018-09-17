#pragma once

class CheckStorage
{
public:

	virtual void availableStorage();

	virtual void availableMemory();

	unsigned long long minAvailStorage; //checking for available storage in bytes
 
};