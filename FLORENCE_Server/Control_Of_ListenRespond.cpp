#include "Control_Of_ListenRespond.h"

bool* ptr_Flag_IO_ThreadState = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::Control_Of_ListenRespond()
{
    bool* ptr_Flag_IO_ThreadState = new bool(true);
    while (ptr_Flag_IO_ThreadState == nullptr) { /* wait untill class constructed */ }
}
FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::~Control_Of_ListenRespond()
{
    delete ptr_Flag_IO_ThreadState;
}

bool FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::getFlag_IO_ThreadState()
{
    return flag_IO_ThreadState;
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::setFlag_IO_ThreadState(bool value)
{
    flag_IO_ThreadState = value;
}