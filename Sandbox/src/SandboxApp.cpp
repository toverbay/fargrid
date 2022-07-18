#include <Fargrid.h>

/* glm test
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

glm::mat4 camera(float translate, glm::vec2 const& rotate)
{
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -translate));

	view = glm::rotate(view, rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));

	return projection * view * model;
}
*/

class ExampleLayer : public Fargrid::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		/* glm test
		auto cam = camera(5.0f, { 0.5f, 0.5f });
		*/
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
