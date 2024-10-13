#include "Praise0_Algorithm.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace
{

    Praise0_Algorithm::Praise0_Algorithm()
    {
    }

    Praise0_Algorithm::~Praise0_Algorithm()
    {
    }

    void Praise0_Algorithm::do_Praise(
        Praise0_Input* ptr_In_SubSet,
        Praise0_Output* ptr_Out_SubSet
    )
    {
        bool result = false;
        if (this->ptr_In_SubSet->get_A() == true && this->ptr_In_SubSet->get_B() == true)
        {
            this->ptr_Out_SubSet->setResultForPraise_0(true);
        }
        else if (this->ptr_In_SubSet->get_A() == true && this->ptr_In_SubSet->get_B() == false)
        {
            this->ptr_Out_SubSet->setResultForPraise_0(false);
        }
        else if (this->ptr_In_SubSet->get_A() == false && this->ptr_In_SubSet->get_B() == true)
        {
            this->ptr_Out_SubSet->setResultForPraise_0(false);
        }
        else if (this->ptr_In_SubSet->get_A() == false && this->ptr_In_SubSet->get_B() == false)
        {
            this->ptr_Out_SubSet->setResultForPraise_0(false);
        }
    }
}
