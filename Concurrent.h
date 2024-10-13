#pragma once
#include "Concurrent.h"
#include "Control_Of_Concurrent.h"
#include "Control_Of_Data.h"
#include "Control_Of_Execute.h"
#include "Control_Of_LaunchConcurrency.h"
#include "Control_Of_Output.h"
#include "Control_Of_WriteEnable.h"
#include "Data.h"
#include "Global.h"
#include "Input.h"
#include "LaunchConcurrency.h"
#include "Output.h"
#include "user_files/Praise0_Algorithm.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"
#include "WriteEnable.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace
{
    class Concurrent
    {
    public:
        Concurrent();
        virtual ~Concurrent();
        void initialise_Control();
        static void thread_Concurrency(
            unsigned char concurrent_coreId,
            unsigned char* ptr_MyNumImplementedCores,
            Concurrent* ptr_Concurrent,
            Concurrent::Control_Of_Concurrent* prt_Control_Of_Concurrent,
            FLORENCE::Framework::Server::Data::Control_Of_Data* ptr_Control_Of_Data,
            FLORENCE::Framework::Server::Execute::Control_Of_Execute* ptr_Control_Of_Execute,
            FLORENCE::Framework::Server::Execute::LaunchConcurrency::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            FLORENCE::Framework::Server::Data::Output::Control_Of_Output* ptr_Control_Of_Output,
            FLORENCE::Framework::Server::Execute::WriteEnable::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            FLORENCE::Framework::Server::Data* ptr_Data,
            FLORENCE::Framework::Server::Global* ptr_Global,
            FLORENCE::Framework::Server::Data::Input* ptr_InputBuffer,
            std::vector<FLORENCE::Framework::Server::Data::Input*>* ptr_InputStack,
            FLORENCE::Framework::Server::Execute::LaunchConcurrency* ptr_LaunchConcurrency,
            FLORENCE::Framework::Server::Data::Output* ptr_Output,
            std::vector<FLORENCE::Framework::Server::Data::Output*>* ptr_OutputStack,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::Framework::Server::Data::Praise0_Input* ptr_Input_Subset,
            FLORENCE::Framework::Server::Data::Praise0_Output* ptr_Output_Subset,
            FLORENCE::Framework::Server::Execute::WriteEnable* ptr_WriteEnable
        );

        void do_Concurrent_Algorithm_For_PraiseEventId(
            int* ptr_praiseEventId,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::Framework::Server::Data::Praise0_Input* ptr_Input_Subset,
            FLORENCE::Framework::Server::Data::Praise0_Output* ptr_Output_Subset
        );
        Praise0_Algorithm* get_Algorithm_Subset();//TODO CLASS T
        class Control_Of_Concurrent* get_Control_Of_Concurrent();

        void set_Algorithm_Subset(Praise0_Algorithm* value_algorithm);//TODO CLASS T

    protected:

    private:
        class Control_Of_Concurrent* ptr_Control_Of_Concurrent;
        class Praise0_Algorithm* ptr_Algorithms_Subset;//TODO CLASS T

    };
}