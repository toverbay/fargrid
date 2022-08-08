#pragma once

#include "Fargrid/Renderer/VertexArray.h"

namespace Fargrid {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override final;
		virtual void Unbind() const override final;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> vertexBuffer) override final;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> indexBuffer) override final;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;

	private:
		uint32_t m_RendererID;
	};

}
