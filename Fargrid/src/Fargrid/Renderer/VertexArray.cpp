#include "fgpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Fargrid {

    VertexArray* Fargrid::VertexArray::Create()
    {
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:
		{
			FG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		}
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}

		FG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
