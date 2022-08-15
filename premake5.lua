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
IncludeDir["stb"] = "Fargrid/vendor/stb"

group "Dependencies"
    include "Fargrid/vendor/GLFW"
    include "Fargrid/vendor/Glad"
    include "Fargrid/vendor/imgui"

group ""

project "Fargrid"
    location "Fargrid"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl",
        "%{prj.name}/vendor/stb/**.h",
        "%{prj.name}/vendor/stb/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "FG_PLATFORM_WINDOWS",
            "FG_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        -- I will keep this around for possible use with the CLI project.
        -- postbuildcommands
        -- {
        --     ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        -- }

        buildoptions {
            -- Remove this when 'externalwarnings "Off" is available'
            -- "/external:W0"
        }

    filter "configurations:Debug"
        defines "FG_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "FG_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "FG_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

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
        "Fargrid/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Fargrid"
    }

    filter "system:windows"
        systemversion "latest"
        buildoptions {
            -- Remove this when 'externalwarnings "Off" is available'
            -- "/external:W0"
        }

        defines
        {
            "FG_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "FG_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "FG_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "FG_DIST"
        runtime "Release"
        optimize "on"
