#include "Application.h"
#include "Fargrid/Events/ApplicationEvent.h"
#include "Fargrid/Log.h"

namespace Fargrid {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
			FG_TRACE(e);
		}

		while (true);
	}

}