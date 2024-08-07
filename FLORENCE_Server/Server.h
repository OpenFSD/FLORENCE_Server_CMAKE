#pragma once
#include "Algorithms.h"
#include "Data.h"
#include "Execute.h"
#include "Global.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        class Server
        {
        public:
            Server();
            virtual ~Server();
            class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* get_Algorithms();
            class FLORENCE::FrameworkSpace::ServerSpace::Data* get_Data();
            class FLORENCE::FrameworkSpace::ServerSpace::Execute* get_Execute();
            class FLORENCE::FrameworkSpace::ServerSpace::Global* get_Global();

        protected:

        private:
            static class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* ptr_Algorithms;
            static class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data;
            static class FLORENCE::FrameworkSpace::ServerSpace::Execute* ptr_Execute;
            static class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global;
        };
    }
}