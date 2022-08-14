#include <Fargrid.h>

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>

class ExampleLayer : public Fargrid::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
	{
		m_VertexArray.reset(Fargrid::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.2f, 0.1f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.6f, 0.1f, 0.2f, 1.0f,
		};

		std::shared_ptr<Fargrid::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Fargrid::VertexBuffer::Create(vertices, sizeof(vertices)));

		Fargrid::BufferLayout layout = {
			{ Fargrid::ShaderDataType::Float3, "a_Position" },
			{ Fargrid::ShaderDataType::Float4, "a_Color" },
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Fargrid::IndexBuffer> indexBuffer;
		indexBuffer.reset(Fargrid::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Fargrid::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
		};

		std::shared_ptr<Fargrid::VertexBuffer> squareVB;
		squareVB.reset(Fargrid::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Fargrid::ShaderDataType::Float3, "a_Position" },
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Fargrid::IndexBuffer> squareIB;
		squareIB.reset(Fargrid::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
	#version 450 core

	layout(location = 0) in vec3 a_Position;
	layout(location = 1) in vec4 a_Color;

	uniform mat4 u_ViewProjection;
	uniform mat4 u_Transform;

	out vec3 v_Position;
	out vec4 v_Color;

	void main()
	{
		v_Position = a_Position;
		v_Color = a_Color;
		gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
	}			
)";

		std::string fragmentSrc = R"(
	#version 450 core

	layout(location = 0) out vec4 color;

	in vec3 v_Position;
	in vec4 v_Color;

	void main()
	{
		color = vec4(v_Position * 0.5 + 0.5, 1.0);
		color = v_Color;
	}			
)";

		m_Shader.reset(new Fargrid::Shader(vertexSrc, fragmentSrc));

		std::string flatColorShaderVertexSrc = R"(
	#version 450 core

	layout(location = 0) in vec3 a_Position;

	uniform mat4 u_ViewProjection;
	uniform mat4 u_Transform;

	void main()
	{
		gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
	}			
)";

		std::string flatColorShaderFragmentSrc = R"(
	#version 450 core

	layout(location = 0) out vec4 color;

	uniform vec4 u_Color;

	void main()
	{
		color = u_Color;
	}			
)";

		m_FlatColorShader.reset(new Fargrid::Shader(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));
	}

	void OnUpdate(Fargrid::Timestep ts) override
	{
		float time = ts;

		// For debugging...
		// FG_TRACE("Delta time: {0}s ({1}ms)", time, ts.GetMilliseconds());

		if (Fargrid::Input::IsKeyPressed(FG_KEY_LEFT))
			m_CameraPosition.x -= m_CameraMoveSpeed * time;
		else if (Fargrid::Input::IsKeyPressed(FG_KEY_RIGHT))
			m_CameraPosition.x += m_CameraMoveSpeed * time;

		if (Fargrid::Input::IsKeyPressed(FG_KEY_UP))
			m_CameraPosition.y += m_CameraMoveSpeed * time;
		else if (Fargrid::Input::IsKeyPressed(FG_KEY_DOWN))
			m_CameraPosition.y -= m_CameraMoveSpeed * time;

		if (Fargrid::Input::IsKeyPressed(FG_KEY_A))
			m_CameraZRotationDeg += m_CameraRotationSpeed * time;
		else if (Fargrid::Input::IsKeyPressed(FG_KEY_D))
			m_CameraZRotationDeg -= m_CameraRotationSpeed * time;

		Fargrid::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotationZ(m_CameraZRotationDeg);

		Fargrid::Renderer::BeginScene(m_Camera);
		{
			static glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

			glm::vec4 redColor(0.8f, 0.2f, 0.3f, 1.0f);
			glm::vec4 blueColor(0.2f, 0.3f, 0.8f, 1.0f);

			for (int y = -6; y < 6; y++)
			{
				for (int x = -6; x < 6; x++)
				{
					glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
					if ((x + y) % 2 == 0) // Checkerboard pattern
						m_FlatColorShader->UploadUniformFloat4("u_Color", redColor);
					else
						m_FlatColorShader->UploadUniformFloat4("u_Color", blueColor);
					Fargrid::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
				}
			}

			Fargrid::Renderer::Submit(m_Shader, m_VertexArray);
		}
		Fargrid::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnEvent(Fargrid::Event& event) override
	{
		//Fargrid::EventDispatcher dispatcher(event);
		//dispatcher.Dispatch<Fargrid::KeyPressedEvent>(FG_BIND_EVENT_FN(ExampleLayer::OnKeyPressedEvent));
	}

	//bool OnKeyPressedEvent(Fargrid::KeyPressedEvent& event)
	//{

	//	return false;
	//}

private:
	std::shared_ptr<Fargrid::Shader> m_Shader;
	std::shared_ptr<Fargrid::VertexArray> m_VertexArray;

	std::shared_ptr<Fargrid::Shader> m_FlatColorShader;
	std::shared_ptr<Fargrid::VertexArray> m_SquareVA;

	Fargrid::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraZRotationDeg = 0.0f;
	float m_CameraMoveSpeed = 3.5f;			// units/second
	float m_CameraRotationSpeed = 180.0f;	// degrees/second
};

class Sandbox : public Fargrid::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Fargrid::Application* Fargrid::CreateApplication()
{
	return new Sandbox();
}
