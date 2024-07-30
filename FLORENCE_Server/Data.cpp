#include "Data.h"

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_O44f_Data = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_DistributeBuffer = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_InputRefferenceOfCore[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURRENT CORES
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input** ptr_Array_InputRefferenceOfCore = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_OutputRefferenceOfCore[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURRENT CORES
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output** ptr_Array_OutputRefferenceOfCore = nullptr;
std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_StackOfInputPraise = nullptr;
std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_StackOfDistributeBuffer = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer = nullptr;
//===
//===
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* prt_Praise0_Input = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* prt_Praise0_Outut = nullptr;
//===
//===

FLORENCE::FrameworkSpace::ServerSpace::Data::Data(unsigned char* ptr_NumberOfImplementedCores)
{
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_Of_Data = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data();
    while (ptr_Control_Of_Data == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_DistributeBuffer = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output();
    while (ptr_DistributeBuffer == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_InputRefferenceOfCore[3] = {
        new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input(),
        new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input(),
        new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input()
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
    {
        while (ptr_InputRefferenceOfCore[index] == nullptr) { /* wait untill created */ }
    }
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input** ptr_Array_InputRefferenceOfCore = ptr_InputRefferenceOfCore;
    while (ptr_Array_InputRefferenceOfCore == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_OutputRefferenceOfCore[3] = {
        new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output(),
        new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output(),
        new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output()
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
    {
        while (ptr_OutputRefferenceOfCore[index] == nullptr) { /* wait untill created */ }
    }
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output** ptr_Array_OutputRefferenceOfCore = ptr_OutputRefferenceOfCore;
    while (ptr_Array_OutputRefferenceOfCore == nullptr) { /* wait untill created */ }
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_StackOfInputPraise = new std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>;
    while (ptr_StackOfInputPraise == nullptr) { /* wait untill created */ }
    ptr_StackOfInputPraise->resize(2);
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_StackOfDistributeBuffer = new std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>;
    while (ptr_StackOfDistributeBuffer == nullptr) { /* wait untill created */ }
    ptr_StackOfDistributeBuffer->resize(2);
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input();
    while (ptr_PraiseBuffer == nullptr) { /* wait untill created */ }
    //===
    //===
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* prt_Praise0_Input = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input();
    while (prt_Praise0_Input == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* prt_Praise0_Outut = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output();
    while (prt_Praise0_Outut == nullptr) { /* wait untill created */ }
    //===
    //===
}

FLORENCE::FrameworkSpace::ServerSpace::Data::~Data()
{
    delete ptr_Control_Of_Data;
    delete ptr_DistributeBuffer;
    for (int index = 0; index < 3; index++)
    {
        delete ptr_InputRefferenceOfCore[index];
        delete ptr_OutputRefferenceOfCore[index];
    }
    delete ptr_StackOfInputPraise;
    delete ptr_StackOfDistributeBuffer;
    delete ptr_PraiseBuffer;
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* FLORENCE::FrameworkSpace::ServerSpace::Data::get_Control_Of_Data()
{
    return ptr_Control_Of_Data;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* FLORENCE::FrameworkSpace::ServerSpace::Data::get_DistributeBuffer()
{
    return nullptr;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* FLORENCE::FrameworkSpace::ServerSpace::Data::get_InputRefferenceOfCore(unsigned char concurrent_coreId)
{
    return ptr_Array_InputRefferenceOfCore[concurrent_coreId];
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* FLORENCE::FrameworkSpace::ServerSpace::Data::get_OutputRefferenceOfCore(unsigned char concurrent_coreId)
{
    return ptr_Array_OutputRefferenceOfCore[concurrent_coreId];
}

std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* FLORENCE::FrameworkSpace::ServerSpace::Data::get_StackOfInputPraise()
{
    return ptr_StackOfInputPraise;
}

std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* FLORENCE::FrameworkSpace::ServerSpace::Data::get_StackOfDistributeBuffer()
{
    return ptr_StackOfDistributeBuffer;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* FLORENCE::FrameworkSpace::ServerSpace::Data::get_PraiseBuffer()
{
    return ptr_PraiseBuffer;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_DistributeBuffer(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* value_Output)
{
    ptr_DistributeBuffer = value_Output;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_InputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* value_Input)
{
    ptr_Array_InputRefferenceOfCore[concurrent_coreId] = value_Input;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* value_Output)
{
    ptr_Array_OutputRefferenceOfCore[concurrent_coreId] = value_Output;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_PraiseBuffer(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* value_Input)
{
    ptr_PraiseBuffer = value_Input;
}