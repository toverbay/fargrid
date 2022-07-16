#include "fgpch.h"

#include "Application.h"
#include "Fargrid/Events/ApplicationEvent.h"
#include "Fargrid/Log.h"

namespace Fargrid {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		while (m_IsRunning)
		{
			m_Window->OnUpdate();
		}
	}

}