#pragma once

#include "Fargrid/Renderer/Texture.h"

namespace Fargrid {

    class OpenGLTexture2D : public Texture2D
    {
    public:
        OpenGLTexture2D(const std::string& path);
        virtual ~OpenGLTexture2D();

        virtual uint32_t GetWidth() const override final { return m_Width; }
        virtual uint32_t GetHeight() const override final { return m_Height; }

        virtual void Bind(uint32_t slot = 0) const override final;

    private:
        std::string m_Path;
        uint32_t m_Width;
        uint32_t m_Height;

    private:
        uint32_t m_RendererID = -1;
    };

}