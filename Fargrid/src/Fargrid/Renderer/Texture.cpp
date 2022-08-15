#include "fgpch.h"

#include "Texture.h"
#include "Fargrid/Renderer/Renderer.h"
#include "Fargrid/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Fargrid {

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
        {
            FG_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;
        }
        case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
        }

        FG_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}