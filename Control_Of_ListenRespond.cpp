#include "Control_Of_ListenRespond.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace
{
    bool Control_Of_ListenRespond::flag_IO_ThreadState = false;

    Control_Of_ListenRespond::Control_Of_ListenRespond()
    {
        //ptr_Flag_IO_ThreadState = new bool(true);
    }
    Control_Of_ListenRespond::~Control_Of_ListenRespond()
    {

    }

    bool Control_Of_ListenRespond::getFlag_IO_ThreadState()
    {
        return flag_IO_ThreadState;
    }

    void Control_Of_ListenRespond::setFlag_IO_ThreadState(bool value)
    {
        flag_IO_ThreadState = value;
    }
}