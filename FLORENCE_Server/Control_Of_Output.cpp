#include "Control_Of_Output.h"

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output::Control_Of_Output()
{

}
FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output::~Control_Of_Output()
{

}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output::selectSet_Output_Subset_For_Given_PraiseEventId(
	int* ptr_praiseEventId, 
	class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_Output
)
{
	switch (*ptr_praiseEventId)
	{
		//===
		//===
	case 0:
		ptr_Output->set_OutputBuffer_Subset(new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output());
		break;

	case 1:

		break;
		//===
		//===
	}
}