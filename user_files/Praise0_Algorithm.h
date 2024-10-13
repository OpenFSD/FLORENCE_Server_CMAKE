#pragma once
#include "Praise0_Input.h"
#include "Praise0_Output.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace
{
    class Praise0_Algorithm
    {
    public:
        Praise0_Algorithm();
        virtual ~Praise0_Algorithm();
        void do_Praise(
            class Praise0_Input* ptr_In_SubSet,
            class Praise0_Output* ptr_Out_SubSet
        );

    protected:

    private:

    };
}