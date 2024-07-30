#include "Execute.h"

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable = nullptr;
std::thread* ptr_Thread_WithCoreId[4] = { nullptr, nullptr, nullptr, nullptr };//NUMBER OF CORES

FLORENCE::FrameworkSpace::ServerSpace::Execute::Execute(
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute(ptr_MyNumImplementedCores);
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency(ptr_Global, ptr_MyNumImplementedCores);
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable(ptr_Global, ptr_MyNumImplementedCores);
}

FLORENCE::FrameworkSpace::ServerSpace::Execute::~Execute()
{
    delete ptr_Control_Of_Execute;
    delete ptr_LaunchConcurrency;
    delete ptr_WriteEnable;
    for (int index = 0; index < 4; index++)
    {
        delete ptr_Thread_WithCoreId[index];
    }//NUMBER OF CORES
}

void FLORENCE::FrameworkSpace::ServerSpace::Execute::initialise()
{
    class FLORENCE::FrameworkSpace::Server* ptr_Server = FLORENCE::Framework::get_Server();
    ptr_Thread_WithCoreId[0] = new std::thread(
        AlgorithmsSpace::ListenRespond::thread_IO_ListenDistribute,
        unsigned char(0),
        ptr_Server->get_Global()->get_NumCores(),
        ptr_Server->get_Execute()->get_Control_Of_Execute(),
        ptr_Server->get_Data()->get_Control_Of_Data(),
        ptr_Server->get_Execute()->get_LaunchConcurrency(),
        ptr_Server->get_Algorithms()->get_ListenRespond()->get_Control_Of_ListenRespond(),
        ptr_Server->get_Execute()->get_WriteEnable(),
        ptr_Server->get_Data(),
        ptr_Server->get_Global(),
        ptr_Server->get_Data()->get_StackOfInputPraise(),
        ptr_Server->get_Execute()->get_LaunchConcurrency(),
        ptr_Server->get_Data()->get_StackOfDistributeBuffer(),
        ptr_Server->get_Data()->get_PraiseBuffer(),
        ptr_Server->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
        ptr_Server->get_Execute()->get_WriteEnable()
    );
    for (unsigned char index = 1; index <= *ptr_Server->get_Global()->get_NumCores(); index++)
    {
        ptr_Thread_WithCoreId[index] = new std::thread(
            AlgorithmsSpace::Concurrent::thread_Concurrency,
            unsigned char(index),
            ptr_Server->get_Global()->get_NumCores(),
            ptr_Server->get_Algorithms()->get_Concurren_Array(index),
            ptr_Server->get_Algorithms()->get_Concurren_Array(index)->get_Control_Of_Concurrent(),
            ptr_Server->get_Data()->get_Control_Of_Data(),
            ptr_Server->get_Execute()->get_Control_Of_Execute(),
            ptr_Server->get_Execute()->get_LaunchConcurrency(),
            ptr_Server->get_Execute()->get_WriteEnable(),
            ptr_Server->get_Data(),
            ptr_Server->get_Global(),
            ptr_Server->get_Data()->get_PraiseBuffer(),
            ptr_Server->get_Data()->get_StackOfInputPraise(),
            ptr_Server->get_Execute()->get_LaunchConcurrency(),
            ptr_Server->get_Data()->get_DistributeBuffer(),
            ptr_Server->get_Data()->get_StackOfDistributeBuffer(),
            ptr_Server->get_Algorithms()->get_Concurren_Array(index)->get_Algorithm_Subset(),
            ptr_Server->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
            ptr_Server->get_Data()->get_DistributeBuffer()->get_OutputBuffer_Subset(),
            ptr_Server->get_Execute()->get_WriteEnable()
        );
    }
    while (ptr_Server->get_Execute()->get_Control_Of_Execute()->getFlag_SystemInitialised(ptr_Server->get_Global()->get_NumCores()) != false)
    {

    }
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* FLORENCE::FrameworkSpace::ServerSpace::Execute::get_Control_Of_Execute()
{
    return ptr_Control_Of_Execute;
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* FLORENCE::FrameworkSpace::ServerSpace::Execute::get_LaunchConcurrency()
{
    return ptr_LaunchConcurrency;
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* FLORENCE::FrameworkSpace::ServerSpace::Execute::get_WriteEnable()
{
    return ptr_WriteEnable;
}
