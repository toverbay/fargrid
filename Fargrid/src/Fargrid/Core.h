#pragma once

#include <memory>

#ifdef FG_PLATFORM_WINDOWS
#if FG_DYNAMIC_LINK
    #ifdef FG_BUILD_DLL
        #define FG_API __declspec(dllexport)
    #else
        #define FG_API __declspec(dllimport)
    #endif
#else
    #define FG_API
#endif
#else
    #error Fargrid only supports Windows for now
#endif

#ifdef FG_DEBUG
    #define FG_ENABLE_ASSERTS
#endif

#ifdef FG_ENABLE_ASSERTS
    #define FG_ASSERT(x, ...) { if(!(x)) { FG_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define FG_CORE_ASSERT(x, ...) { if(!(x)) { FG_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define FG_ASSERT(x, ...)
    #define FG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define FG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Fargrid {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;

}