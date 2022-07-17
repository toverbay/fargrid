#include <Fargrid.h>

class ExampleLayer : public Fargrid::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Fargrid::Event& event) override
	{
		FG_TRACE("{0}", event);
	}

};
class Sandbox : public Fargrid::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Fargrid::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Fargrid::Application* Fargrid::CreateApplication()
{
	return new Sandbox();
}
