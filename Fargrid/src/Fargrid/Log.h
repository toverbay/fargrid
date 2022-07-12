#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Fargrid {

	class FG_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logging macros
#define FG_CORE_TRACE(...) ::Fargrid::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FG_CORE_INFO(...)  ::Fargrid::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FG_CORE_WARN(...)  ::Fargrid::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FG_CORE_ERROR(...) ::Fargrid::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FG_CORE_FATAL(...) ::Fargrid::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client logging macros
#define FG_TRACE(...)      ::Fargrid::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FG_INFO(...)       ::Fargrid::Log::GetClientLogger()->info(__VA_ARGS__)
#define FG_WARN(...)       ::Fargrid::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FG_ERROR(...)      ::Fargrid::Log::GetClientLogger()->error(__VA_ARGS__)
#define FG_FATAL(...)      ::Fargrid::Log::GetClientLogger()->fatal(__VA_ARGS__)
