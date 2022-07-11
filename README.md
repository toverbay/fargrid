# Fargrid

Yet another attempt at a game engine based on Cherno's [Hazel Game Engine Series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT).

Disclaimer: I am neither a professional game programmer nor a very strong C++ programmer.

I am a professional software engineer working on C# and JavasScript projects, so I thought it might be fun to do something a little different. The plan is to follow along with Cherno's Hazel development videos and adapt it to a game engine I could use in a C# project. It might be cool. It might be an epic failure. Either way, it should be interesting.

## Notes from the videos

- I actually started the project by following along in the [Project Setup](https://www.youtube.com/watch?v=KG8cAGvn9d4&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=4) video. I used "Fargrid" whereever Cherno used "Hazel" and "FG" whereever he used "HZ".

  - [commit](https://github.com/toverbay/fargrid/commit/99a2bc8522aec981c8acf18860b87e6e66d57259)

- I followed along with the [Entry Point](https://www.youtube.com/watch?v=meARMOmTLgE&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=5) video to set up the application entry point.

  - [commit](https://github.com/toverbay/fargrid/commit/b75e544c897352924e707d8ecb9b91a7728059ee)

- I followed along with the [Logging](https://www.youtube.com/watch?v=dZr-53LAlOw&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=6) video to set up core and application logging using the [spdlog](https://github.com/gabime/spdlog) library. Not sure I like using git submodules to bring in spdlog. I'd probably just copy the header, but I'm no C++ expert. Also, I had to use `/external:W0` in both projects to get rid of all the compiler warning spam from spdlog.

  - [commit](https://github.com/toverbay/fargrid/commit/3a2ddbb2dd3af3f159128796c53114eab508cc5d)

- I followed along with the [Premake](https://www.youtube.com/watch?v=sULV3aB2qeU&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=7) video to add premake and create a Lua file to automatically generate the solution & project files. Pretty cool! I've used CMake before and hated it. Premake seemed to be a better experience, although I did have some trouble getting it to set the startup project to "Sandbox". I tried adding the [startproject](https://premake.github.io/docs/startproject/) option, but it didn't seem to work. I ended up manually setting "Sandbox" as the startup project.

  - [commit](https://github.com/toverbay/fargrid/commit/?)

- I intend to create a C# project called `Fargrid-Client` or something in the future. Specifically, when Cherno decides to convert Hazel to a static library, I will create an additional C++ CLI project to export to .NET. That's when things should start to get really interesting. Stay tuned.
