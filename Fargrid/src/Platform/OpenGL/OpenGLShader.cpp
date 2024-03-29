#include "fgpch.h"
#include "OpenGLShader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

namespace Fargrid {

    OpenGLShader::OpenGLShader(const std::string& vertexSrc, std::string& fragmentSrc)
    {
        // Create an empty vertex shader handle
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

        // Send the vertex shader source code to GL
        // Note that std::string's .c_str is NULL character terminated.
        const char* source = vertexSrc.c_str();
        glShaderSource(vertexShader, 1, &source, 0);

        // Compile the vertex shader
        glCompileShader(vertexShader);

        GLint isCompiled = 0;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(vertexShader);

            FG_CORE_ERROR("{0}", infoLog.data());
            FG_CORE_ASSERT(false, "Vertex shader compilation failure!");
            return;
        }

        // Create an empty fragment shader handle
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        // Send the fragment shader source code to GL
        // Note that std::string's .c_str is NULL character terminated.
        source = fragmentSrc.c_str();
        glShaderSource(fragmentShader, 1, &source, 0);

        // Compile the fragment shader
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(fragmentShader);
            // Either of them. Don't leak shaders.
            glDeleteShader(vertexShader);

            FG_CORE_ERROR("{0}", infoLog.data());
            FG_CORE_ASSERT(false, "Fragment shader compilation failure!");
            return;
        }

        // Vertex and fragment shaders are successfully compiled.
        // Now time to link them together into a program.
        // Get a program object.
        GLuint program = glCreateProgram();

        // Attach our shaders to our program
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);

        // Link our program
        glLinkProgram(program);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(program);
            // Don't leak shaders either.
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            FG_CORE_ERROR("{0}", infoLog.data());
            FG_CORE_ASSERT(false, "Shader link failure!");
            return;
        }

        // Always detach shaders after a successful link.
        glDetachShader(program, vertexShader);
        glDetachShader(program, fragmentShader);
        m_RendererID = program;
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_RendererID);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniformMatrix3fv(location, 1, false, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniformMatrix4fv(location, 1, false, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformFloat(const std::string& name, float value)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform1f(location, value);
    }

    void OpenGLShader::UploadUniformFloat2(const std::string& name, const glm::vec2 values)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform2f(location, values.x, values.y);
    }

    void OpenGLShader::UploadUniformFloat3(const std::string& name, const glm::vec3 values)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform3f(location, values.x, values.y, values.z);
    }

    void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4 values)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform4f(location, values.x, values.y, values.z, values.w);
    }

    void OpenGLShader::UploadUniformInt(const std::string& name, int value)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform1i(location, value);
    }

    void OpenGLShader::UploadUniformInt2(const std::string& name, const glm::i32vec2 values)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform2i(location, values.x, values.y);
    }

    void OpenGLShader::UploadUniformInt3(const std::string& name, const glm::i32vec3 values)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform3i(location, values.x, values.y, values.z);
    }

    void OpenGLShader::UploadUniformInt4(const std::string& name, const glm::i32vec4 values)
    {
        GLint location = GetUniformLocation(name.c_str());
        FG_CORE_ASSERT(location >= 0, "Uniform does not exist!");
        glUniform4i(location, values.x, values.y, values.z, values.w);
    }

    GLint OpenGLShader::GetUniformLocation(const std::string& name) const
    {
        if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
            return m_UniformLocationCache[name];

        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        m_UniformLocationCache[name] = location;

        return location;
    }

}