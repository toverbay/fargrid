#pragma once

#include <string>

#include "Fargrid/Core.h"

namespace Fargrid {

    class Shader
    {
    public:
        virtual ~Shader() = default;
        
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        static Ref<Shader> Create(const std::string& vertexSrc, std::string& fragmentSrc);
    };
}