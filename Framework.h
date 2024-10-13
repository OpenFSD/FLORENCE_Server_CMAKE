#pragma once
#include "Server.h"

namespace FLORENCE
{
	class Framework
	{
	public:
		Framework();
		virtual ~Framework();
		static class Server* get_Server();

	protected:

	private:
		static class Server* ptr_Server;
	};
}