#include <Fargrid.h>

class Sandbox : public Fargrid::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Fargrid::Application* Fargrid::CreateApplication()
{
	return new Sandbox();
}
