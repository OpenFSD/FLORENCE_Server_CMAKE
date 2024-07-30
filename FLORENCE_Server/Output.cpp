#include "Output.h"

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* praiseOutputBuffer_Subset = nullptr;//ToDo CLASS T
int* ptr_out_PraiseEventId = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::Output()
{
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output();
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* praiseOutputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output();//ToDo CLASS T
    int* ptr_out_PraiseEventId = new int(0);
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::~Output()
{
    delete ptr_Control_Of_Output;
    delete praiseOutputBuffer_Subset;
    delete ptr_out_PraiseEventId;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* get_Control_Of_Output()
{
    return ptr_Control_Of_Output;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* get_OutputBuffer_Subset()
{
    return praiseOutputBuffer_Subset;
}


int* getPraiseEventId()
{
    return ptr_out_PraiseEventId;
}

void set_OutputBuffer_Subset(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* value)
{
    praiseOutputBuffer_Subset = value;
}

void setPraiseEventId(int value)
{
    ptr_out_PraiseEventId = &value;
}

