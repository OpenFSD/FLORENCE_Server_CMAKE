#include "Control_Of_Concurrent.h"
#include "Framework.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace
{

	Control_Of_Concurrent::Control_Of_Concurrent()
	{

	}
	Control_Of_Concurrent::~Control_Of_Concurrent()
	{

	}

	void Control_Of_Concurrent::selectSet_Algorithm_Subset_For_Given_PraiseEventId(
		int* ptr_praiseEventId,
		unsigned char concurrent_coreId
	)
	{
		FLORENCE::Framework::Server* server = FLORENCE::Framework::get_Server();// Get_framework()->get_Server();
		switch (*ptr_praiseEventId)
		{
			//===
			//===	
		case 0:
			server->get_Algorithms()->get_Concurren_Array(concurrent_coreId)->set_Algorithm_Subset(new FLORENCE::Framework::Server::Algorithms::Praise0_Algorithm());
			break;

		case 1:
			//TODO for each praise
			break;
			//===
			//===	
		}
	}
}