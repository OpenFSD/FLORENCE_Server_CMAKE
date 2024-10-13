#include "Server.h"

namespace FLORENCE::FrameworkSpace
{
    class Algorithms* Server::ptr_Algorithms = NULL;
    class Data* Server::ptr_Data = NULL;
    class Execute* Server::ptr_Execute = NULL;
    class Global* Server::ptr_Global = NULL;

    Server::Server()
    {
        this->ptr_Global = new Server::Global();
        while (this->ptr_Global == NULL) { /* wait untill created */ }

        this->ptr_Algorithms = new Server::Algorithms(ptr_Global->get_NumCores());
        while (this->ptr_Algorithms == NULL) { /* wait untill created */ }

        this->ptr_Data = new Server::Data(ptr_Global->get_NumCores());
        while (this->ptr_Data == NULL) { /* wait untill created */ }
        this->ptr_Data->initialise_Control();

        this->ptr_Execute = new Server::Execute(ptr_Global, ptr_Global->get_NumCores());
        while (this->ptr_Execute == NULL) { /* wait untill created */ }
        this->ptr_Execute->initialise_Control(ptr_Global->get_NumCores(), ptr_Global);
    }

    Server::~Server()
    {
        delete this->ptr_Global;
        delete this->ptr_Algorithms;
        delete this->ptr_Data;
        delete this->ptr_Execute;
    }

    class Algorithms* Server::get_Algorithms()
    {
        return this->ptr_Algorithms;
    }

    class Data* Server::get_Data()
    {
        return this->ptr_Data;
    }

    class Execute* Server::get_Execute()
    {
        return this->ptr_Execute;
    }

    class Global* Server::get_Global()
    {
        return this->ptr_Global;
    }
}