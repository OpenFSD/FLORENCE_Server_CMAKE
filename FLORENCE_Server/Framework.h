#pragma once
#include "Server.h"

namespace FLORENCE
{
	class Framework
	{
	public:
		Framework();
		virtual ~Framework();
		static class FLORENCE::FrameworkSpace::Server* get_Server();

	protected:

	private:
		static class FLORENCE::FrameworkSpace::Server* ptr_Server;
	};
}
