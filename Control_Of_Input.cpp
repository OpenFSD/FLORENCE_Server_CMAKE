#include "Control_Of_Input.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace
{

	Control_Of_Input::Control_Of_Input()
	{

	}
	Control_Of_Input::~Control_Of_Input()
	{

	}

	void Control_Of_Input::selectSet_Input_Subset_For_Given_PraiseEventId(int* ptr_praiseEventId)
	{
		class FLORENCE::Framework::Server* server = FLORENCE::Framework::get_Server();
		switch (*ptr_praiseEventId)
		{
			//===
			//===
		case 0:
			server->get_Data()->get_PraiseBuffer()->set_InputBuffer_SubSet(new class FLORENCE::Framework::Server::Data::Praise0_Input());
			break;

		case 1:

			break;
			//===
			//===

		}
	}
}