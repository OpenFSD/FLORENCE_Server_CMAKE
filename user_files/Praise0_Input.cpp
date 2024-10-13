#include "Praise0_Input.h"

namespace FLORENCE::FrameworkSpace::ServerSpace::DataSpace
{

	bool Praise0_Input::a = false;
	bool Praise0_Input::b = false;

	Praise0_Input::Praise0_Input()
	{
		this->a = bool(false);
		this->b = bool(false);
	}

	Praise0_Input::~Praise0_Input()
	{
	}

	bool Praise0_Input::get_A()
	{
		return a;
	}

	bool Praise0_Input::get_B()
	{
		return b;
	}

	void Praise0_Input::set_A(bool value)
	{
		a = value;
	}

	void Praise0_Input::set_B(bool value)
	{
		b = value;
	}
}