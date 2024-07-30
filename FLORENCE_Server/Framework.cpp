#include "Framework.h"

class FLORENCE::FrameworkSpace::Server* ptr_Server = nullptr;

FLORENCE::Framework::Framework()
{
	class FLORENCE::FrameworkSpace::Server* ptr_Server = new class FLORENCE::FrameworkSpace::Server();
	while (ptr_Server == nullptr) { /* wait untill created */ }
	this->get_Server()->initialise(this->get_Server());
}

FLORENCE::Framework::~Framework()
{
	delete ptr_Server;
}

class FLORENCE::FrameworkSpace::Server* FLORENCE::Framework::get_Server()
{
	return ptr_Server;
}
