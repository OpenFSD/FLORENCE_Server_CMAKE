#include "Control_Of_ListenRespond.h"

using FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespondSpace;

bool flag_IO_ThreadState = false;

Control_Of_ListenRespond()
{
    ptr_Flag_IO_ThreadState = new bool(true);
}
~Control_Of_ListenRespond()
{

}

bool getFlag_IO_ThreadState()
{
    return flag_IO_ThreadState;
}

void setFlag_IO_ThreadState(bool value)
{
    flag_IO_ThreadState = value;
}