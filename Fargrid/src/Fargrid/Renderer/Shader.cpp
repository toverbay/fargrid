#include "fgpch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Fargrid {

    Ref<Shader> Shader::Create(const std::string& vertexSrc, std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
            {
                FG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(vertexSrc, fragmentSrc);
        }

        FG_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
