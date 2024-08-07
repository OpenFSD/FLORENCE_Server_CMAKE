#include <iostream>
#include "Framework.h"

class FLORENCE::FrameworkSpace::Server* FLORENCE::Framework::ptr_Server = nullptr;

FLORENCE::Framework::Framework()
{
	class FLORENCE::FrameworkSpace::Server* ptr_Server = new class FLORENCE::FrameworkSpace::Server();
	while (ptr_Server == nullptr) { /* wait untill created */ }
    
    std::cout << "        ,     \\      /      ,";
    std::cout << "       / \\    )\\ __ /(     / \\ ";
    std::cout << "      /   \\   (_\\  /_)    /   \\ ";
    std::cout << "____ / ____\\__ \\@  @/ ___/_____\\_____";
    std::cout << "|              |\\../|               |";
    std::cout << "|               \\VV/                |";
    std::cout << "|  FLORANCE - FULL STACK DEVELOPMENT |";
    std::cout << "|        DEVELOPERS TEMPLATE        |";
    std::cout << "|___________________________________|";
    std::cout << "|    / \\ /        \\\\        \\ /\\    |";
    std::cout << "|  /    V          ))        V   \\  |";
    std::cout << "|/                //               \\| ";
    std::cout << "`                 V                 '";

    ptr_Server->get_Execute()->initialise_Threads();
}

FLORENCE::Framework::~Framework()
{
	delete FLORENCE::Framework::ptr_Server;
}

class FLORENCE::FrameworkSpace::Server* FLORENCE::Framework::get_Server()
{
	return ptr_Server;
}
