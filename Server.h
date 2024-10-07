#pragma once
#include "Algorithms.h"
#include "Data.h"
#include "Execute.h"
#include "Global.h"

namespace FLORENCE::FrameworkSpace
{
    class Server
    {
    public:
        Server();
        virtual ~Server();
        class ServerSpace::Algorithms* get_Algorithms();
        class ServerSpace::Data* get_Data();
        class ServerSpace::Execute* get_Execute();
        class ServerSpace::Global* get_Global();

    protected:

    private:
        class ServerSpace::Algorithms* ptr_Algorithms;
        class ServerSpace::Data* ptr_Data;
        class ServerSpace::Execute* ptr_Execute;
        class ServerSpace::Global* ptr_Global;
    };
}