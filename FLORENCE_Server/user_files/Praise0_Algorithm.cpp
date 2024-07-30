#include "Praise0_Algorithm.h"

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm::Praise0_Algorithm()
{
}

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm::~Praise0_Algorithm()
{
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm::do_Praise0(
    FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_InSubSet,
    FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_OutSubSet
)
{
    bool result = false;
    if (ptr_InSubSet->get_A() == true && ptr_InSubSet->get_B() == true)
    {
        ptr_OutSubSet->setResultForPraise_0(true);
    }
    else if (ptr_InSubSet->get_A() == true && ptr_InSubSet->get_B() == false)
    {
        ptr_OutSubSet->setResultForPraise_0(false);
    }
    else if (ptr_InSubSet->get_A() == false && ptr_InSubSet->get_B() == true)
    {
        ptr_OutSubSet->setResultForPraise_0(false);
    }
    else if (ptr_InSubSet->get_A() == false && ptr_InSubSet->get_B() == false)
    {
        ptr_OutSubSet->setResultForPraise_0(false);
    }
}
