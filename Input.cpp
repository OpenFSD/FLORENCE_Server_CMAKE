#include "Input.h"

using FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace;

int* ptr_in_praiseEventId = nullptr;

Input()
{
    this->ptr_praiseInputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input();//TODO CLASS T
    while (this->ptr_praiseInputBuffer_Subset == nullptr) { /* wait untill created */ }
    int* ptr_in_praiseEventId = new int(0);
    while (this->ptr_in_praiseEventId == nullptr) { /* wait untill created */ }
}

~Input()
{
    delete ptr_Control_Of_Input;
    delete ptr_praiseInputBuffer_Subset;
    delete ptr_in_praiseEventId;
}

void initialise_Control()
{
    this->ptr_Control_Of_Input = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input();
    while (this->ptr_Control_Of_Input == nullptr) { /* wait untill created */ }
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* get_Control_Of_Input()
{
    return this->ptr_Control_Of_Input;
}

int* getPraiseEventId()
{
    return this->ptr_in_praiseEventId;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* get_InputBufferSubset()
{
    return this->ptr_praiseInputBuffer_Subset;
}

void set_InputBuffer_SubSet(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* value)
{
    this->ptr_praiseInputBuffer_Subset = value;
}

void setPraiseEventId(int value)
{
    this->ptr_in_praiseEventId = &value;
}