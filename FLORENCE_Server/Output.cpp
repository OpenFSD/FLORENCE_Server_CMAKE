#include "Output.h"

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_Control_Of_Output = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::praiseOutputBuffer_Subset = nullptr;//ToDo CLASS T
int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_out_PraiseEventId = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::Output()
{
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* praiseOutputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output();//ToDo CLASS T
    while (praiseOutputBuffer_Subset == nullptr) { /* wait untill created */ }
    int* ptr_out_PraiseEventId = new int(0);
    while (ptr_out_PraiseEventId == nullptr) { /* wait untill created */ }
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::~Output()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_Control_Of_Output;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::praiseOutputBuffer_Subset;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_out_PraiseEventId;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::initialise_Control()
{
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output();
    while (ptr_Control_Of_Output == nullptr) { /* wait untill created */ }
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::get_Control_Of_Output()
{
    return ptr_Control_Of_Output;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::get_OutputBuffer_Subset()
{
    return praiseOutputBuffer_Subset;
}


int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::getPraiseEventId()
{
    return ptr_out_PraiseEventId;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::set_OutputBuffer_Subset(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* value)
{
    praiseOutputBuffer_Subset = value;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::setPraiseEventId(int value)
{
    ptr_out_PraiseEventId = &value;
}

