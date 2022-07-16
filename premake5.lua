workspace "Fargrid"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    startproject "Sandbox" 

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Fargrid/vendor/GLFW/include"

include "Fargrid/vendor/GLFW"

project "Fargrid"
    location "Fargrid"
    kind "SharedLib"
    language "C++"
    -- Doesn't work with current version of Premake
    -- externalwarnings "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "fgpch.h"
    pchsource "Fargrid/src/fgpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions {
            -- Remove this when 'externalwarnings "Off" is available'
            "/external:W0"
        }
        defines
        {
            "FG_PLATFORM_WINDOWS",
            "FG_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "FG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FG_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    -- Doesn't work with current version of Premake
    -- externalwarnings "Off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Fargrid/vendor/spdlog/include",
        "Fargrid/src"
    }

    links
    {
        "Fargrid"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions {
            -- Remove this when 'externalwarnings "Off" is available'
            "/external:W0"
        }

        defines
        {
            "FG_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FG_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FG_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FG_DIST"
        optimize "On"
