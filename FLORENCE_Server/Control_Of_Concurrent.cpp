#include "Control_Of_Concurrent.h"

using namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace;

Control_Of_Concurrent::Control_Of_Concurrent()
{

}
Control_Of_Concurrent::~Control_Of_Concurrent()
{

}

void Control_Of_Concurrent::select_Concurrent_Algorithm_Given_PraiseEventId(
	int* ptr_praiseEventId,
	Praise0_Algorithm* ptr_Algorithm_Subset,
	FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
	FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset
)
{
	switch (*ptr_praiseEventId)
	{
		//===
		//===	
	case 0:
		ptr_Algorithm_Subset->do_Praise0(
			ptr_Input_Subset,
			ptr_Output_Subset
		);
		break;

	case 1:
		//TODO for each praise
		break;
		//===
		//===	
	}
}