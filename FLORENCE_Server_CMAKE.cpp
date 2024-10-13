// FLORENCE_Server.cpp : Defines the entry point for the application.
#include "FLORENCE_Server_CMAKE.h"

namespace FLORENCE
{
    int main()
    {
        //System.Console.WriteLine("FLORENCE: SERVER START");
        class Framework* ptr_Framework = new class FLORENCE::Framework();
        while (ptr_Framework == NULL) { /* wait untill created */ }
        return 0;
    }
}