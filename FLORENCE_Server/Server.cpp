#include "Server.h"

class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* ptr_Algorithms = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::Execute* ptr_Execute = nullptr;

FLORENCE::FrameworkSpace::Server::Server()
{
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global = new class FLORENCE::FrameworkSpace::ServerSpace::Global();
    while (ptr_Global == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* ptr_Algorithms = new class FLORENCE::FrameworkSpace::ServerSpace::Algorithms(ptr_Global->get_NumCores());
    while (ptr_Algorithms == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data = new class FLORENCE::FrameworkSpace::ServerSpace::Data(ptr_Global->get_NumCores());
    while (ptr_Data == nullptr) { /* wait untill created */ }
    class FLORENCE::FrameworkSpace::ServerSpace::Execute* ptr_Execute = new class FLORENCE::FrameworkSpace::ServerSpace::Execute(ptr_Global->get_NumCores(), ptr_Global);
    while (ptr_Execute == nullptr) { /* wait untill created */ }
}
FLORENCE::FrameworkSpace::Server::~Server()
{
    delete ptr_Global;
    delete ptr_Algorithms;
    delete ptr_Data;
    delete ptr_Execute;
}
void FLORENCE::FrameworkSpace::Server::initialise(class FLORENCE::FrameworkSpace::Server* ptr_Server)
{
    ptr_Server->get_Execute()->initialise(ptr_Server);
}

class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* FLORENCE::FrameworkSpace::Server::get_Algorithms()
{
    return ptr_Algorithms;
}

class FLORENCE::FrameworkSpace::ServerSpace::Data* FLORENCE::FrameworkSpace::Server::get_Data()
{
    return ptr_Data;
}

class FLORENCE::FrameworkSpace::ServerSpace::Execute* FLORENCE::FrameworkSpace::Server::get_Execute()
{
    return ptr_Execute;
}

class FLORENCE::FrameworkSpace::ServerSpace::Global* FLORENCE::FrameworkSpace::Server::get_Global()
{
    return ptr_Global;
}

