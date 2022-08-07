#pragma once

#include "Core.h"

#include "Window.h"
#include "Fargrid/LayerStack.h"
#include "Fargrid/Events/ApplicationEvent.h"

#include "Fargrid/ImGui/ImGuiLayer.h"

#include "Fargrid/Renderer/Shader.h"
#include "Fargrid/Renderer/Buffer.h"
#include "Fargrid/Renderer/VertexArray.h"

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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_IsRunning = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

	private:
		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}