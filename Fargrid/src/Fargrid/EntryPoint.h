#pragma once

#ifdef FG_PLATFORM_WINDOWS

extern Fargrid::Application* Fargrid::CreateApplication();

int main(int argc, char** argv)
{
	Fargrid::Log::Init();
	FG_CORE_WARN("Initialized Log!");
	FG_INFO("Hello from Fargrid!");

	auto app = Fargrid::CreateApplication();
	app->Run();
	delete app;
}

#endif