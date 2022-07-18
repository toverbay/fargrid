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
IncludeDir["Glad"] = "Fargrid/vendor/Glad/include"
IncludeDir["ImGui"] = "Fargrid/vendor/imgui"
IncludeDir["glm"] = "Fargrid/vendor/glm"

group "Dependencies"
    include "Fargrid/vendor/GLFW"
    include "Fargrid/vendor/Glad"
    include "Fargrid/vendor/imgui"

group ""

project "Fargrid"
    location "Fargrid"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        buildoptions {
            -- Remove this when 'externalwarnings "Off" is available'
            "/external:W0"
        }
        defines
        {
            "FG_PLATFORM_WINDOWS",
            "FG_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "FG_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "FG_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "FG_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        "Fargrid/src",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Fargrid"
    }

    filter "system:windows"
        cppdialect "C++17"
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
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "FG_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "FG_DIST"
        runtime "Release"
        optimize "On"
