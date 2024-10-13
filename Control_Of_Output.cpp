#include "Control_Of_Output.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace
{
	Control_Of_Output::Control_Of_Output()
	{

	}
	Control_Of_Output::~Control_Of_Output()
	{

	}

	void Control_Of_Output::selectSet_Output_Subset_For_Given_PraiseEventId(
		int* ptr_praiseEventId,
		unsigned char concurrent_coreId
	)
	{
		class FLORENCE::Framework::Server* server = FLORENCE::Framework::get_Server();
		switch (*ptr_praiseEventId)
		{
//===
//===
		case 0:
			server->get_Data()->get_OutputRefferenceOfCore(concurrent_coreId)->set_OutputBuffer_Subset(new class FLORENCE::Framework::Server::Data::Praise0_Output());
			break;

		case 1:

			break;
//===
//===
		}
	}
}