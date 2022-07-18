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
		// Ex: Polling for keys
		if (Fargrid::Input::IsKeyPressed(FG_KEY_TAB))
			FG_TRACE("Tab key is pressed!");
	}

	void OnEvent(Fargrid::Event& event) override
	{
		// Ex: Log printable keys
		if (event.GetEventType() == Fargrid::EventType::KeyPressed)
		{
			Fargrid::KeyPressedEvent& e = (Fargrid::KeyPressedEvent&)event;
			FG_TRACE("{0}", (char)e.GetKeyCode());
		}
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
