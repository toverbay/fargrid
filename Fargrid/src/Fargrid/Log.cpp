#include "fgpch.h"

#include "Log.h"

#pragma warning(push, 0)        
//Some includes with unfixable warnings
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)

namespace Fargrid {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("FARGRID");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}