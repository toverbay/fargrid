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

project "Fargrid"
    location "Fargrid"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/external:W0"

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
        buildoptions "/external:W0"

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
