#pragma once

#include "Core.h"

namespace Fargrid {

	class FG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}