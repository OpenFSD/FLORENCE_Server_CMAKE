#include <iostream>
#include "Framework.h"

namespace FLORENCE
{
    class Server* Framework::ptr_Server = NULL;

    Framework::Framework()
    {
        std::cout << "FLORENCE: Framework" << std::endl;
        ptr_Server = new Framework::Server();
        while (ptr_Server == NULL) { /* wait untill created */ }

        std::cout << "        ,     \\      /      ," << std::endl;
        std::cout << "       / \\    )\\ __ /(     / \\ " << std::endl;
        std::cout << "      /   \\   (_\\  /_)    /   \\ " << std::endl;
        std::cout << "____ / ____\\__ \\@  @/ ___/_____\\_____" << std::endl;
        std::cout << "|              |\\../|               |" << std::endl;
        std::cout << "|               \\VV/                |" << std::endl;
        std::cout << "|  FLORANCE - FULL STACK DEVELOPMENT |" << std::endl;
        std::cout << "|        DEVELOPERS TEMPLATE        |" << std::endl;
        std::cout << "|___________________________________|" << std::endl;
        std::cout << "|    / \\ /        \\\\        \\ /\\    |" << std::endl;
        std::cout << "|  /    V          ))        V   \\  |" << std::endl;
        std::cout << "|/                //               \\| " << std::endl;
        std::cout << "`                 V                 '" << std::endl;

        get_Server()->get_Execute()->initialise_Threads();
    }

    Framework::~Framework()
    {
        delete ptr_Server;
    }

    class Server* Framework::get_Server()
    {
        return ptr_Server;
    }
}