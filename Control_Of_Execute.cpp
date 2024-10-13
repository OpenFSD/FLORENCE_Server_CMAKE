#include "Control_Of_Execute.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace
{
	bool Control_Of_Execute::flag_SystemInitialised = bool(true);
	bool Control_Of_Execute::flag_ThreadInitialised[4] = { bool(true), bool(true), bool(true), bool(true) };//NUMBER OF CORES

	Control_Of_Execute::Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores)
	{
		this->flag_SystemInitialised = bool(true);
		this->flag_ThreadInitialised[4] = { true, true, true, true };//NUMBER OF CORES
	}

	Control_Of_Execute::~Control_Of_Execute()
	{

	}

	bool Control_Of_Execute::getFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores)
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

	bool Control_Of_Execute::getFlag_ThreadInitialised(unsigned char coreId)
	{
		return flag_ThreadInitialised[coreId];
	}

	void Control_Of_Execute::setConditionCodeOfThisThreadedCore(unsigned char coreId)
	{
		//Todo
		setFlag_ThreadInitialised(coreId);
	}

	void Control_Of_Execute::setFlag_ThreadInitialised(unsigned char coreId)
	{
		flag_ThreadInitialised[coreId] = false;
	}
}