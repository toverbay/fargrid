#pragma once

#include "Core.h"

#include "Window.h"
#include "Fargrid/LayerStack.h"
#include "Fargrid/Events/ApplicationEvent.h"

#include "Fargrid/Core/Timestep.h"

#include "Fargrid/ImGui/ImGuiLayer.h"

namespace Fargrid {

	class FG_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}