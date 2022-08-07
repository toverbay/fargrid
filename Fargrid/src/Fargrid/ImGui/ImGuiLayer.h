#pragma once

#include "Fargrid/Layer.h"

#include "Fargrid/Events/ApplicationEvent.h"
#include "Fargrid/Events/KeyEvent.h"
#include "Fargrid/Events/MouseEvent.h"

namespace Fargrid {

	class FG_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}