#include "Execute.h"

namespace FLORENCE::FrameworkSpace::ServerSpace
{
    class Control_Of_Execute* Execute::ptr_Control_Of_Execute = NULL;
    class LaunchConcurrency* Execute::ptr_LaunchConcurrency = NULL;
    std::thread* Execute::ptr_Thread_WithCoreId[4] = NULL;//NUMBER OF CORES
    class WriteEnable* Execute::ptr_WriteEnable = NULL;

    Execute::Execute(
        class FLORENCE::Framework::Server::Global* ptr_Global,
        unsigned char* ptr_MyNumImplementedCores
    )

        this->ptr_Control_Of_Execute = new class Control_Of_Execute();
        while (this->ptr_Control_Of_Execute == NULL) { /* wait untill created */ }

        this->ptr_LaunchConcurrency = new class LaunchConcurrency();
        while (this->ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
        this->ptr_LaunchConcurrency->initialise_Control(ptr_Global, ptr_MyNumImplementedCores);

        this->ptr_Thread_WithCoreId[4] = { NULL, NULL, NULL, NULL };
        for (int index = 0; index < 4; index++)
        {
            while (this->ptr_Thread_WithCoreId[index] == NULL) { /* wait untill created */ }
        }

        this->ptr_WriteEnable = new class WriteEnable();
        while (this->ptr_WriteEnable == NULL) { /* wait untill created */ }
        this->ptr_WriteEnable->initialise_Control(ptr_Global, ptr_MyNumImplementedCores);
    }

    Execute::~Execute()
    {
        delete this->ptr_Control_Of_Execute;
        delete this->ptr_LaunchConcurrency;
        delete this->ptr_WriteEnable;
        for (int index = 0; index < 4; index++)
        {
            delete this->ptr_Thread_WithCoreId[index];
        }//NUMBER OF CORES
    }

    void Execute::initialise_Threads()
    {
        ptr_Thread_WithCoreId[0] = new std::thread(
            FLORENCE::Get_framework()->get_Server()->get_Algorithms()->get_ListenRespond()->thread_IO_ListenDistribute,
            unsigned char(0),
            FLORENCE::Get_framework()->get_Server()->get_Global()->get_NumCores(),
            FLORENCE::Get_framework()->get_Server()->get_Execute()->get_Control_Of_Execute(),
            FLORENCE::Get_framework()->get_Server()->get_Data()->get_Control_Of_Data(),
            FLORENCE::Get_framework()->get_Server()->get_Execute()->get_LaunchConcurrency(),
            FLORENCE::Get_framework()->get_Server()->get_Algorithms()->get_ListenRespond()->get_Control_Of_ListenRespond(),
            FLORENCE::Get_framework()->get_Server()->get_Execute()->get_WriteEnable(),
            FLORENCE::Get_framework()->get_Server()->get_Data(),
            FLORENCE::Get_framework()->get_Server()->get_Global(),
            FLORENCE::Get_framework()->get_Server()->get_Data()->get_StackOfInputPraise(),
            FLORENCE::Get_framework()->get_Server()->get_Execute()->get_LaunchConcurrency(),
            FLORENCE::Get_framework()->get_Server()->get_Data()->get_StackOfDistributeBuffer(),
            FLORENCE::Get_framework()->get_Server()->get_Data()->get_PraiseBuffer(),
            FLORENCE::Get_framework()->get_Server()->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
            FLORENCE::Get_framework()->get_Server()->get_Execute()->get_WriteEnable()
        );
        for (unsigned char index = 1; index <= *FLORENCE::Get_framework()->get_Server()->get_Global()->get_NumCores(); index++)
        {
            ptr_Thread_WithCoreId[index] = new std::thread(
                FLORENCE::Get_framework()->get_Server()->get_Algorithms()->get_Concurren_Array(index)->thread_Concurrency,
                unsigned char(index),
                FLORENCE::Get_framework()->get_Server()->get_Global()->get_NumCores(),
                FLORENCE::Get_framework()->get_Server()->get_Algorithms()->get_Concurren_Array(index),
                FLORENCE::Get_framework()->get_Server()->get_Algorithms()->get_Concurren_Array(index)->get_Control_Of_Concurrent(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_Control_Of_Data(),
                FLORENCE::Get_framework()->get_Server()->get_Execute()->get_Control_Of_Execute(),
                FLORENCE::Get_framework()->get_Server()->get_Execute()->get_LaunchConcurrency(),
                FLORENCE::Get_framework()->get_Server()->get_Execute()->get_WriteEnable(),
                FLORENCE::Get_framework()->get_Server()->get_Data(),
                FLORENCE::Get_framework()->get_Server()->get_Global(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_PraiseBuffer(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_StackOfInputPraise(),
                FLORENCE::Get_framework()->get_Server()->get_Execute()->get_LaunchConcurrency(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_DistributeBuffer(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_StackOfDistributeBuffer(),
                FLORENCE::Get_framework()->get_Server()->get_Algorithms()->get_Concurren_Array(index)->get_Algorithm_Subset(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
                FLORENCE::Get_framework()->get_Server()->get_Data()->get_DistributeBuffer()->get_OutputBuffer_Subset(),
                FLORENCE::Get_framework()->get_Server()->get_Execute()->get_WriteEnable()
            );
        }
        while (FLORENCE::Get_framework()->get_Server()->get_Execute()->get_Control_Of_Execute()->getFlag_SystemInitialised(FLORENCE::Get_framework()->get_Server()->get_Global()->get_NumCores()) != false)
        {

        }
    }
}