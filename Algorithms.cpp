#include "Algorithms.h"

using FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace;

Algorithms(unsigned char* ptr_NumberOfImplementedCores)
{
    this->ptr_New_Concurrent = new class Concurrent();
    this->ptr_New_Concurrent->initialise_Control();

    Concurrent* ptr_Concurrent[3] = {
        this->ptr_New_Concurrent,
        this->ptr_New_Concurrent,
        this->ptr_New_Concurrent
    };//NUMBER OF CONCURRENT CORES
    delete this->ptr_New_Concurrent;

    this->ptr_Concurrent_Array = this->ptr_Concurrent;
    while (this->ptr_Concurrent_Array == nullptr) { /* wait untill class constructed */ }

    this->ptr_ListenRespond = new class ListenRespond();
    while (this->ptr_ListenRespond == nullptr) { /* wait untill class constructed */ }
    this->ptr_ListenRespond->initialise_Control();
//===
//===
    this->ptr_Praise0_Algorithms = new class Praise0_Algorithm();
    while (this->ptr_Praise0_Algorithms == nullptr) { /* wait untill class constructed */ }
//===
//===
}

~Algorithms()
{
    for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
    {
        delete ptr_Concurrent[index];
    }
    delete ptr_Concurrent_Array;
    delete ptr_ListenRespond;
    delete ptr_Praise0_Algorithms;
}

class Concurrent* get_Concurren_Array(unsigned char concurrent_coreId)
{
    return this->ptr_Concurrent[concurrent_coreId];
}

class ListenRespond* get_ListenRespond()
{
    return this->ptr_ListenRespond;
}

//===
//===
class Praise0_Algorithm* get_Praise0_Algorithm()
{
    return this->ptr_Praise0_Algorithms;
}
//===
//===