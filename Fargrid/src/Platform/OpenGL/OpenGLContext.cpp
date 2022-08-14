#include "fgpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Fargrid {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		FG_CORE_ASSERT(m_WindowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glfwSwapInterval(1);
		FG_CORE_ASSERT(status, "Failed to initialize Glad!");

		FG_CORE_INFO("OpenGL Info:");
		FG_CORE_INFO("  - Vendor: {0}", glGetString(GL_VENDOR));
		FG_CORE_INFO("  - Renderer: {0}", glGetString(GL_RENDERER));
		FG_CORE_INFO("  - Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}