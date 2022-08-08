#include "fgpch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Fargrid {

	/*=============================================================================*/
	/* VertexBuffer                                                                */
	/*=============================================================================*/

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
			{
				FG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
				return nullptr;
			}
			case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		FG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	/*=============================================================================*/
	/* IndexBuffer                                                                 */
	/*=============================================================================*/

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
		{
			FG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		}
		case RendererAPI::API::OpenGL:
			return new OpenGLIndexBuffer(indices, size);
		}

		FG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}