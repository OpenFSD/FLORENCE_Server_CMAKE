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
            ConcurrentSpace::Control_Of_Concurrent* prt_Control_Of_Concurrent,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_Of_Data,
            FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute,
            FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output,
            FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data,
            FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_InputBuffer,
            std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_InputStack,
            FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_Output,
            std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_OutputStack,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset,
            FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
        );

        void do_Concurrent_Algorithm_For_PraiseEventId(
            int* ptr_praiseEventId,
            Praise0_Algorithm* ptr_Algorithm_Subset,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
            FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset
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