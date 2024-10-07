#include "Control_Of_Execute.h"

using FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_ExecuteSpace;

bool flag_SystemInitialised = bool(true);
bool flag_ThreadInitialised[4] = { bool(true), bool(true), bool(true), bool(true) };//NUMBER OF CORES

Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores)
{
	flag_SystemInitialised = bool(true);
	flag_ThreadInitialised[4] = { true, true, true, true };//NUMBER OF CORES
}

~Control_Of_Execute()
{

}

bool getFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores)
{
	for (int index = 0; index < *ptr_MyNumImplementedCores; index++)
	{
		flag_SystemInitialised = false;
		if (flag_ThreadInitialised[index] == true)
		{
			flag_SystemInitialised = true;
		}
	}
	return flag_SystemInitialised;
}

bool getFlag_ThreadInitialised(unsigned char coreId)
{
	return flag_ThreadInitialised[coreId];
}

void setConditionCodeOfThisThreadedCore(unsigned char coreId)
{
	//Todo
	setFlag_ThreadInitialised(coreId);
}

void setFlag_ThreadInitialised(unsigned char coreId)
{
	flag_ThreadInitialised[coreId] = false;
}