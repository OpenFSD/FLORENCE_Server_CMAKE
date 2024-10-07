#include "Data.h"

using FLORENCE::FrameworkSpace::ServerSpace::DataSpace;

Data(unsigned char* ptr_NumberOfImplementedCores)
{
    this->ptr_new_Input = new class Input();
    while (this->ptr_new_Input == nullptr) { /* wait untill created */ }
    this->ptr_new_Input->initialise_Control();
    
    this->ptr_new_Output = new class Output();
    while (this->ptr_new_Output == nullptr) { /* wait untill created */ }
    this->ptr_new_Output->initialise_Control();

    this->ptr_DistributeBuffer = this->ptr_new_Output;
    while (this->ptr_DistributeBuffer == nullptr) { /* wait untill created */ }

    class Input* ptr_InputRefferenceOfCore[3] = {
        this->ptr_new_Input,
        this->ptr_new_Input,
        this->ptr_new_Input
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
    {
        while (this->ptr_InputRefferenceOfCore[index] == nullptr) { /* wait untill created */ }
    }

    this->ptr_InputRefferenceOfCore_Array = this->ptr_InputRefferenceOfCore;
    while (this->ptr_InputRefferenceOfCore_Array == nullptr) { /* wait untill created */ }
    
    class Output* ptr_OutputRefferenceOfCore[3] = {
        this->ptr_new_Output,
        this->ptr_new_Output,
        this->ptr_new_Output
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
    {
        while (this->ptr_OutputRefferenceOfCore[index] == nullptr) { /* wait untill created */ }
    }

    this->ptr_OutputRefferenceOfCore_Array = this->ptr_OutputRefferenceOfCore;
    while (this->ptr_OutputRefferenceOfCore_Array == nullptr) { /* wait untill created */ }

    this->ptr_StackOfInputPraise = new std::vector<class Input*>;
    while (this->ptr_StackOfInputPraise == nullptr) { /* wait untill created */ }
    this->ptr_StackOfInputPraise->resize(1);
    this->ptr_StackOfInputPraise->at(0) = this->ptr_new_Input;

    this->ptr_StackOfDistributeBuffer = new std::vector<class Output*>;
    while (this->ptr_StackOfDistributeBuffer == nullptr) { /* wait untill created */ }
    this->ptr_StackOfDistributeBuffer->resize(1);
    this->ptr_StackOfDistributeBuffer->at(0) = this->ptr_new_Output;

    this->ptr_PraiseBuffer = this->ptr_new_Input;
    while (this->ptr_PraiseBuffer == nullptr) { /* wait untill created */ }

    //===
    //===
    this->prt_Praise0_Input = new class Praise0_Input();
    while (this->prt_Praise0_Input == nullptr) { /* wait untill created */ }
    this->prt_Praise0_Outut = new class Praise0_Output();
    while (this->prt_Praise0_Outut == nullptr) { /* wait untill created */ }
    //===
    //===
    delete ptr_new_Input;
    delete ptr_new_Output;
}

~Data()
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

void initialise_Control()
{
    this->ptr_Control_Of_Data = new class Control_Of_Data();
    while (this->ptr_Control_Of_Data == nullptr) { /* wait untill created */ }
}

Control_Of_Data* get_Control_Of_Data()
{
    return this->ptr_Control_Of_Data;
}

class Output* get_DistributeBuffer()
{
    return this->ptr_DistributeBuffer;
}

class Input* get_InputRefferenceOfCore(unsigned char concurrent_coreId)
{
    return this->ptr_InputRefferenceOfCore_Array[concurrent_coreId];
}

class Output* get_OutputRefferenceOfCore(unsigned char concurrent_coreId)
{
    return this->ptr_OutputRefferenceOfCore_Array[concurrent_coreId];
}

std::vector<class Input*>* get_StackOfInputPraise()
{
    return this->ptr_StackOfInputPraise;
}

std::vector<class Output*>* get_StackOfDistributeBuffer()
{
    return this->ptr_StackOfDistributeBuffer;
}

class Input* get_PraiseBuffer()
{
    return this->ptr_PraiseBuffer;
}

void set_DistributeBuffer(class Output* value_Output)
{
    this->ptr_DistributeBuffer = value_Output;
}

void set_InputRefferenceOfCore(unsigned char concurrent_coreId, class Input* value_Input)
{
    this->ptr_InputRefferenceOfCore_Array[concurrent_coreId] = value_Input;
}

void set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class Output* value_Output)
{
    this->ptr_OutputRefferenceOfCore_Array[concurrent_coreId] = value_Output;
}

void set_PraiseBuffer(class Input* value_Input)
{
    this->ptr_PraiseBuffer = value_Input;
}