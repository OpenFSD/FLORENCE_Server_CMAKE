#include "Output.h"

using FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace;

int* ptr_out_PraiseEventId = nullptr;

Output()
{
    this->praiseOutputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output();//ToDo CLASS T
    while (this->praiseOutputBuffer_Subset == nullptr) { /* wait untill created */ }
    int* ptr_out_PraiseEventId = new int(0);
    while (this->ptr_out_PraiseEventId == nullptr) { /* wait untill created */ }
}

~Output()
{
    delete ptr_Control_Of_Output;
    delete praiseOutputBuffer_Subset;
    delete ptr_out_PraiseEventId;
}

void initialise_Control()
{
    this->ptr_Control_Of_Output = new class Control_Of_Output();
    while (this->ptr_Control_Of_Output == nullptr) { /* wait untill created */ }
}

class Control_Of_Output* get_Control_Of_Output()
{
    return this->ptr_Control_Of_Output;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* get_OutputBuffer_Subset()
{
    return this->praiseOutputBuffer_Subset;
}


int* getPraiseEventId()
{
    return this->ptr_out_PraiseEventId;
}

void set_OutputBuffer_Subset(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* value)
{
    this->praiseOutputBuffer_Subset = value;
}

void setPraiseEventId(int value)
{
    this->ptr_out_PraiseEventId = &value;
}

