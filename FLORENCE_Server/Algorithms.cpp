#include "Algorithms.h"

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent** ptr_Array_Concurrent = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURRENT CORES
class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond* ptr_ListenRespond = nullptr;
//===
//===
class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Praise0_Algorithms = nullptr;
//===
//===

FLORENCE::FrameworkSpace::ServerSpace::Algorithms::Algorithms(unsigned char* ptr_NumberOfImplementedCores)
{
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent[3] = {
        new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent(),
        new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent(),
        new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent()
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < 3; index++)
    {
        while (ptr_Concurrent[index] == nullptr) { /* wait untill class constructed */ }
    }//NUMBER OF CONCURRENT CORES
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent** ptr_Array_Concurrent = ptr_Concurrent;
    while (ptr_Array_Concurrent == nullptr) { /* wait untill class constructed */ }
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond* ptr_ListenRespond = new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond();
    while (ptr_ListenRespond == nullptr) { /* wait untill class constructed */ }
//===
    //===
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Praise0_Algorithms = new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm();
    while (ptr_Praise0_Algorithms == nullptr) { /* wait untill class constructed */ }
//===
    //===
}

FLORENCE::FrameworkSpace::ServerSpace::Algorithms::~Algorithms()
{
    for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
    {
        delete ptr_Concurrent[index];
    }
    delete ptr_Array_Concurrent;
    delete ptr_ListenRespond;
    delete ptr_Praise0_Algorithms;
}

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* FLORENCE::FrameworkSpace::ServerSpace::Algorithms::get_Concurren_Array(unsigned char concurrent_coreId)
{
    return ptr_Concurrent[concurrent_coreId];
}

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond* FLORENCE::FrameworkSpace::ServerSpace::Algorithms::get_ListenRespond()
{
    return ptr_ListenRespond;
}

//===
//===
class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* FLORENCE::FrameworkSpace::ServerSpace::Algorithms::get_Praise0_Algorithm()
{
    return ptr_Praise0_Algorithms;
}
//===
//===