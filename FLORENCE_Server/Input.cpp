#include "Input.h"

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_Control_Of_Input = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_praiseInputBuffer_Subset = nullptr;//TODO CLASS T
int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_in_praiseEventId = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::Input()
{
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_praiseInputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input();//TODO CLASS T
    while (ptr_praiseInputBuffer_Subset == nullptr) { /* wait untill created */ }
    int* ptr_in_praiseEventId = new int(0);
    while (ptr_in_praiseEventId == nullptr) { /* wait untill created */ }
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::~Input()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_Control_Of_Input;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_praiseInputBuffer_Subset;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_in_praiseEventId;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::initialise_Control()
{
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* ptr_Control_Of_Input = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input();
    while (ptr_Control_Of_Input == nullptr) { /* wait untill created */ }
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::get_Control_Of_Input()
{
    return ptr_Control_Of_Input;
}

int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::getPraiseEventId()
{
    return ptr_in_praiseEventId;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::get_InputBufferSubset()
{
    return ptr_praiseInputBuffer_Subset;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::set_InputBuffer_SubSet(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* value)
{
    ptr_praiseInputBuffer_Subset = value;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::setPraiseEventId(int value)
{
    ptr_in_praiseEventId = &value;
}