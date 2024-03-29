#pragma once

#include "Fargrid/Renderer/RendererAPI.h"

namespace Fargrid {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override final;
		virtual void Clear() override final;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override final;
	};

}