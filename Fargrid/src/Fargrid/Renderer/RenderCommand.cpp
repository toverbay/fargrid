#include "fgpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Fargrid {
	
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}