#include "fgpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Fargrid {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case Fargrid::ShaderDataType::Float:   return GL_FLOAT;
		case Fargrid::ShaderDataType::Float2:  return GL_FLOAT;
		case Fargrid::ShaderDataType::Float3:  return GL_FLOAT;
		case Fargrid::ShaderDataType::Float4:  return GL_FLOAT;
		case Fargrid::ShaderDataType::Mat3:    return GL_FLOAT;
		case Fargrid::ShaderDataType::Mat4:    return GL_FLOAT;
		case Fargrid::ShaderDataType::Int:     return GL_INT;
		case Fargrid::ShaderDataType::Int2:    return GL_INT;
		case Fargrid::ShaderDataType::Int3:    return GL_INT;
		case Fargrid::ShaderDataType::Int4:    return GL_INT;
		case Fargrid::ShaderDataType::Bool:    return GL_BOOL;
		}

		FG_CORE_ASSERT(false, "Unknown ShaderDataType!");

		return 0;
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> vertexBuffer)
	{
		FG_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		uint32_t elementIndex = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(elementIndex);
			glVertexAttribPointer(elementIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)(UINT_PTR)element.Offset);
			elementIndex++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}
