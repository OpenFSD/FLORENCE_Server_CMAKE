#include "Server.h"

class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* FLORENCE::FrameworkSpace::Server::ptr_Algorithms = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::Data* FLORENCE::FrameworkSpace::Server::ptr_Data = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::Global* FLORENCE::FrameworkSpace::Server::ptr_Global = nullptr;
class FLORENCE::FrameworkSpace::ServerSpace::Execute* FLORENCE::FrameworkSpace::Server::ptr_Execute = nullptr;

FLORENCE::FrameworkSpace::Server::Server()
{
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global = new class FLORENCE::FrameworkSpace::ServerSpace::Global();
    while (ptr_Global == nullptr) { /* wait untill created */ }
    
    class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* ptr_Algorithms = new class FLORENCE::FrameworkSpace::ServerSpace::Algorithms(ptr_Global->get_NumCores());
    while (ptr_Algorithms == nullptr) { /* wait untill created */ }

    class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data = new class FLORENCE::FrameworkSpace::ServerSpace::Data(ptr_Global->get_NumCores());
    while (ptr_Data == nullptr) { /* wait untill created */ }
    ptr_Data->initialise_Control();

    class FLORENCE::FrameworkSpace::ServerSpace::Execute* ptr_Execute = new class FLORENCE::FrameworkSpace::ServerSpace::Execute(ptr_Global, ptr_Global->get_NumCores());
    while (ptr_Execute == nullptr) { /* wait untill created */ }
    ptr_Execute->initialise_Control(ptr_Global->get_NumCores(), ptr_Global);
}
FLORENCE::FrameworkSpace::Server::~Server()
{
    delete FLORENCE::FrameworkSpace::Server::ptr_Global;
    delete FLORENCE::FrameworkSpace::Server::ptr_Algorithms;
    delete FLORENCE::FrameworkSpace::Server::ptr_Data;
    delete FLORENCE::FrameworkSpace::Server::ptr_Execute;
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

