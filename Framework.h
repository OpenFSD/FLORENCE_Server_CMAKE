#pragma once
#include "Server.h"

namespace FLORENCE
{
	class Framework
	{
	public:
		Framework();
		virtual ~Framework();
		class FrameworkSpace::Server* get_Server();

	protected:

	private:
		class FrameworkSpace::Server* ptr_Server;
	};
}
