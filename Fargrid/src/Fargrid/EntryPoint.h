#pragma once

#ifdef FG_PLATFORM_WINDOWS

extern Fargrid::Application* Fargrid::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Fargrid::CreateApplication();
	app->Run();
	delete app;
}

#endif