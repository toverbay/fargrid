#include "fgpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Fargrid {

    Ref<VertexArray> Fargrid::VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
        {
            FG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        }
        case RendererAPI::API::OpenGL: return std::make_shared<OpenGLVertexArray>();
        }

        FG_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
