#include "Server.h"

using FLORENCE::FrameworkSpace::ServerSpace;

Server()
{
    this->ptr_Global = new class Global();
    while (this->ptr_Global == nullptr) { /* wait untill created */ }
    
    this->ptr_Algorithms = new class Algorithms(ptr_Global->get_NumCores());
    while (this->ptr_Algorithms == nullptr) { /* wait untill created */ }

    this->ptr_Data = new class Data(ptr_Global->get_NumCores());
    while (this->ptr_Data == nullptr) { /* wait untill created */ }
    this->ptr_Data->initialise_Control();

    this->ptr_Execute = new class Execute(ptr_Global, ptr_Global->get_NumCores());
    while (this->ptr_Execute == nullptr) { /* wait untill created */ }
    this->ptr_Execute->initialise_Control(ptr_Global->get_NumCores(), ptr_Global);
}
~Server()
{
    delete this->ptr_Global;
    delete this->ptr_Algorithms;
    delete this->ptr_Data;
    delete this->ptr_Execute;
}

class Algorithms* get_Algorithms()
{
    return this->ptr_Algorithms;
}

class Data* get_Data()
{
    return this->ptr_Data;
}

class Execute* get_Execute()
{
    return this->ptr_Execute;
}

class Global* get_Global()
{
    return this->ptr_Global;
}

