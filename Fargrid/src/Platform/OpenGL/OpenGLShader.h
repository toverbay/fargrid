#pragma once

#include "Fargrid/Renderer/Shader.h"

#include <string>
#include <glm/glm.hpp>

namespace Fargrid {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vertexSrc, std::string& fragmentSrc);
		virtual ~OpenGLShader();

		virtual void Bind() const override final;
		virtual void Unbind() const override final;

		void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
		void UploadUniformFloat(const std::string& name, float value);
		void UploadUniformFloat2(const std::string& name, const glm::vec2 values);
		void UploadUniformFloat3(const std::string& name, const glm::vec3 values);
		void UploadUniformFloat4(const std::string& name, const glm::vec4 values);
		void UploadUniformInt(const std::string& name, int value);
		void UploadUniformInt2(const std::string& name, const glm::i32vec2 values);
		void UploadUniformInt3(const std::string& name, const glm::i32vec3 values);
		void UploadUniformInt4(const std::string& name, const glm::i32vec4 values);

	private:
		uint32_t m_RendererID;
	};

}