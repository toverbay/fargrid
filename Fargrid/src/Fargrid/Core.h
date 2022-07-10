#pragma once

#ifdef FG_PLATFORM_WINDOWS
	#ifdef FG_BUILD_DLL
		#define FG_API __declspec(dllexport)
	#else
		#define FG_API __declspec(dllimport)
	#endif
#else
	#error Fargrid only supports Windows for now
#endif