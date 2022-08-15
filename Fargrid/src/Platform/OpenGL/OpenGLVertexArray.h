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

		virtual void AddVertexBuffer(const Ref<VertexBuffer> vertexBuffer) override final;
		virtual void SetIndexBuffer(const Ref<IndexBuffer> indexBuffer) override final;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

	private:
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;

	private:
		uint32_t m_RendererID;
	};

}
