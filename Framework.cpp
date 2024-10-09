#include <iostream>
#include "Framework.h"

using FLORENCE::FrameworkSpace;

Framework()
{
    System.Console.WriteLine("FLORENCE: Framework");
    this->ptr_Server = new class Server();
	while (this->ptr_Server == nullptr) { /* wait untill created */ }
    
    System.Console.WriteLine("        ,     \\      /      ,");
    System.Console.WriteLine("       / \\    )\\ __ /(     / \\ ");
    System.Console.WriteLine("      /   \\   (_\\  /_)    /   \\ ");
    System.Console.WriteLine("____ / ____\\__ \\@  @/ ___/_____\\_____");
    System.Console.WriteLine("|              |\\../|               |");
    System.Console.WriteLine("|               \\VV/                |");
    System.Console.WriteLine("|  FLORANCE - FULL STACK DEVELOPMENT |");
    System.Console.WriteLine("|        DEVELOPERS TEMPLATE        |");
    System.Console.WriteLine("|___________________________________|");
    System.Console.WriteLine("|    / \\ /        \\\\        \\ /\\    |");
    System.Console.WriteLine("|  /    V          ))        V   \\  |");
    System.Console.WriteLine("|/                //               \\| ");
    System.Console.WriteLine("`                 V                 '");
}

~Framework()
{
	delete ptr_Server;
}

class Server* get_Server()
{
	return this->ptr_Server;
}
