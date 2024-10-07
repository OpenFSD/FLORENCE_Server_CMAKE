#pragma once
#include <array>
#include "Concurrent.h"
#include "ListenRespond.h"
#include "user_files/Praise0_Algorithm.h"

namespace FLORENCE::FrameworkSpace::ServerSpace
{
    class Algorithms
    {
    public:
        Algorithms(unsigned char* ptr_NumberOfImplementedCores);
        virtual ~Algorithms();
        class AlgorithmsSpace::Concurrent* get_Concurren_Array(unsigned char concurrent_coreId);
        class AlgorithmsSpace::ListenRespond* get_ListenRespond();

//===
//===
        class AlgorithmsSpace::Praise0_Algorithm* get_Praise0_Algorithm();
//===
//===

    protected:

    private:
        class AlgorithmsSpace::Concurrent** ptr_Concurrent_Array;
        class AlgorithmsSpace::Concurrent* ptr_Concurrent[3];
        class AlgorithmsSpace::ListenRespond* ptr_ListenRespond;
        class AlgorithmsSpace::Concurrent* ptr_New_Concurrent;
//===
//===
        class AlgorithmsSpace::Praise0_Algorithm* ptr_Praise0_Algorithms;
//===
//===



    };
}