#pragma once
#include "Concurrent.h"
#include "Control_Of_Concurrent.h"
#include "Control_Of_Execute.h"
#include "Control_Of_Data.h"
#include "Control_Of_Input.h"
#include "Control_Of_LaunchConcurrency.h"
#include "Control_Of_ListenRespond.h"
#include "Control_Of_Output.h"
#include "Control_Of_WriteEnable.h"
#include "Data.h"
#include "Global.h"
#include "Input.h"
#include "LaunchConcurrency.h"
#include <vector>
#include "Output.h"
#include "user_files/Praise0_Input.h"
#include "WriteEnable.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace
{
    class ListenRespond
    {
    public:
        ListenRespond();
        virtual ~ListenRespond();
        void initialise_Control();
        static void thread_IO_ListenDistribute(
            unsigned char coreId,
            unsigned char* ptr_MyNumImplementedCores,
            class Concurrent* ptr_Concurrent,
            class Concurrent::Control_Of_Concurrent* ptr_Control_Of_Concurrent,
            class FLORENCE::Framework::Server::Execute::Control_Of_Execute* ptr_Control_Of_Execute,
            class FLORENCE::Framework::Server::Data::Control_Of_Data* ptr_Control_Of_Data,
            class FLORENCE::Framework::Server::Data::Input::Control_Of_Input* ptr_Control_Of_Input,
            class FLORENCE::Framework::Server::Execute::LaunchConcurrency::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
            class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond,
            class FLORENCE::Framework::Server::Data::Output::Control_Of_Output* ptr_Control_Of_Output,
            class FLORENCE::Framework::Server::Execute::WriteEnable::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
            class FLORENCE::Framework::Server::Data* ptr_Data,
            class FLORENCE::Framework::Server::Global* ptr_Global,
            std::vector<class FLORENCE::Framework::Server::Data::Input*>* ptr_InputStack,
            class FLORENCE::Framework::Server::Execute::LaunchConcurrency* ptr_LaunchConcurrency,
            std::vector<class FLORENCE::Framework::Server::Data::Output*>* ptr_OutputStack,
            class FLORENCE::Framework::Server::Data::Input* ptr_PraiseBuffer,
            class FLORENCE::Framework::Server::Data::Praise0_Input* ptr_PraiseBuffer_Subset,
            class FLORENCE::Framework::Server::Execute::WriteEnable* ptr_WriteEnable
        );

        class Control_Of_ListenRespond* get_Control_Of_ListenRespond();

    protected:

    private:
        class Control_Of_ListenRespond* ptr_Control_Of_ListenRespond;
    };
}