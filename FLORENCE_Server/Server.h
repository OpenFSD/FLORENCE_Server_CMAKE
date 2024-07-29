#include "Algorithms.h"
#include "Data.h"
#include "Global.h"
#include "Execute.h"
#include "Server.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        class Server
        {
        public:
            Server();
            virtual ~Server();
            static void initialise(FLORENCE::FrameworkSpace::Server* ptr_Server);
            class Algorithms* get_Algorithms();
            class Data* get_Data();
            class Execute* get_Execute();
            class Global* get_Global();

        protected:

        private:
            static class Algorithms* ptr_Algorithms;
            static class Data* ptr_Data;
            static class Execute* ptr_Execute;
            static class Global* ptr_Global;
        };
    }
}