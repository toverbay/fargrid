#pragma once

#include "Fargrid/Core.h"
#include "Fargrid/Events/Event.h"
#include "Fargrid/Core/Timestep.h"

namespace Fargrid {

	class FG_API Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};

}