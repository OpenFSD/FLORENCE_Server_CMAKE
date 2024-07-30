#pragma once
#include "user_files/Praise0_Algorithm.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace AlgorithmsSpace
            {
                namespace ConcurrentSpace
                {
                    class Control_Of_Concurrent
                    {
                    public:
                        Control_Of_Concurrent();
                        virtual ~Control_Of_Concurrent();
                        void select_Concurrent_Algorithm_Given_PraiseEventId(
                            int* ptr_praiseEventId,
                            class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Algorithm_Subset,
                            class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
                            class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset
                        );

                    protected:

                    private:

                    };
                }
            }
        }
    }
}