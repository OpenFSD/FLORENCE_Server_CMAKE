#pragma once
#include "Control_Of_WriteEnable.h"
#include "Global.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace ExecuteSpace
            {
                class WriteEnable
                {
                public:
                    WriteEnable(
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global_pass,
                        unsigned char* ptr_MyNumImplementedCores
                    );
                    virtual ~WriteEnable();
                    static void write_End(
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
                        unsigned char* ptr_coreId,
                        unsigned char* ptr_MyNumImplementedCores,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
                    );
                    static void write_Start(
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
                        unsigned char* ptr_coreId,
                        unsigned char* ptr_MyNumImplementedCores,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
                    );

                    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* get_Control_Of_WriteEnable();

                protected:

                private:
                    static class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable;
                };
            }
        }
    }
}