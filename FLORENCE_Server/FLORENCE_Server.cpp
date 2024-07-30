// FLORENCE_Server.cpp : Defines the entry point for the application.
//
#include "FLORENCE_Server.h"

namespace FLORENCE
{
    class FLORENCE::Framework* ptr_Framework = nullptr;

    int main()
    {
        class FLORENCE::Framework* ptr_Framework = new class FLORENCE::Framework();
        return 0;
    }
}