# Fargrid

Yet another attempt at a game engine. This one is based on Cherno's [Hazel Game Engine Series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT).

Disclaimer: I am neither a professional game programmer nor a very strong C++ programmer.

I am a professional software engineer working on C# and JavasScript projects and I thought it might be fun to do something a little different. The plan is to follow along with Cherno's Hazel development videos and adapt it to a game engine I could use in a C# project. It might be cool. It might be an epic failure. Either way, it should be interesting.

## Notes from the videos

- I started the project by following along in the [Project Setup](https://www.youtube.com/watch?v=KG8cAGvn9d4&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=4) video. I used "Fargrid" wherever Cherno used "Hazel" and "FG" wherever he used "HZ".

  - [commit](https://github.com/toverbay/fargrid/commit/99a2bc8522aec981c8acf18860b87e6e66d57259)

- I followed along with the [Entry Point](https://www.youtube.com/watch?v=meARMOmTLgE&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=5) video to set up the application entry point.

  - [commit](https://github.com/toverbay/fargrid/commit/b75e544c897352924e707d8ecb9b91a7728059ee)

- I followed along with the [Logging](https://www.youtube.com/watch?v=dZr-53LAlOw&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=6) video to set up core and application logging using the [spdlog](https://github.com/gabime/spdlog) library. Not sure I like using git submodules to bring in spdlog. I'd probably just copy the header, but I'm no C++ expert. Also, I had to use `/external:W0` in both projects to get rid of all the compiler warning spam from spdlog.

  - [commit](https://github.com/toverbay/fargrid/commit/3a2ddbb2dd3af3f159128796c53114eab508cc5d)

- I followed along with the [Premake](https://www.youtube.com/watch?v=sULV3aB2qeU&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=7) video to add premake and create a Lua file to automatically generate the solution & project files. Pretty cool! I've used CMake before and hated it. Premake seemed to be a better experience, although I did have some trouble getting it to set the startup project to "Sandbox". I tried adding the [startproject](https://premake.github.io/docs/startproject/) option, but it didn't seem to work. I ended up manually setting "Sandbox" as the startup project.

  - [commit](https://github.com/toverbay/fargrid/commit/26f592220c890d8f114b4fd10afeb9448041566f)

- I followed along with the [Event System](https://www.youtube.com/watch?v=xnopUoZbMEk&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=9) video. It was frustrating at first because I made a really dumb mistake<sup>1</sup>, but I worked it out.

  A continuing source of frustration is that compiler warnings for external includes keep appearing. The `/external:W0` compiler option doesn't seem to work. I either didn't configured it correctly for Premake, I don't completely understand how it's supposed to work, or it just plain doesn't work. I also discovered the [externalwarnings](https://premake.github.io/docs/externalwarnings/) option for Premake, but it just crashed Premake when I tried to use it. *sigh*

  - [commit](https://github.com/toverbay/fargrid/commit/f9f95b16cdff48b428dbb8ce8de859b905010a64)

- I followed along with the [Window Abstraction and GLFW](https://www.youtube.com/watch?v=88dmtleVywk&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=11) video. Cherno adds his own [fork](https://github.com/TheCherno/glfw) of the [GLFW](https://github.com/glfw/glfw) as a submodule and then references it in his project. Now I had a decision to make here: Should I use his fork or create my own fork? I decided to use his fork just to get things started and then create and link my own fork later.

  I immediately ran into issues. The video is almost four years old at the time I'm writing this and both the GLFW project and Cherno's fork of it have had many, many commits in the interim. So I decided to just fork GLFW as it is now and, after a bit of fiddling around, got it working. This was not a cut-and-dried, follow along with the video kind of episode, but it should be easier from this point.

  - [commit](https://github.com/toverbay/fargrid/commit/55003e556c2392d096d6dd15795b454955b976a0)

- I followed along with the [Window Events](https://www.youtube.com/watch?v=r74WxFMIEdU&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=12) video and things went much more smoothly. Now I can respond to keyboard, mouse and window events. Yay!

  - [commit](https://github.com/toverbay/fargrid/commit/c4e13bf8a2b3dbf657b2a779aaea8f1ebe6896f2)

- I followed along with the [Layers](https://www.youtube.com/watch?v=_Kj6BSfM6P4&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=13) video to implement layers and a layer stack. Pretty straightforward concepts: Layers are updated/rendered bottom-to-top and events are bubbled top-to-bottom. I kind of dread the next one, which is adding ImGui. I've struggled with forking & linking external projects, but maybe the lessons learned will make it go better than before.

  - [commit](https://github.com/toverbay/fargrid/commit/2fccebc5ab2830e8afe92f7961d4136885112710)

- I followed along with the [Modern OpenGL (Glad)](https://www.youtube.com/watch?v=HFyHIc89z1g&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=14) video to add modern OpenGL functionality to the project. The [Glad configurator](https://glad.dav1d.de) was pretty cool<sup>2</sup>. Here is the permalink to the [generated files](https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=compatibility&loader=on).

  I didn't see Cherno add the license for Glad to the vendor folder. Not sure if it's necessary, but I went ahead and grabbed the license from the [Glad repo](https://github.com/Dav1dde/glad) anyway.

  - [commit](https://github.com/toverbay/fargrid/commit/19b96efcec6813bdfa008d9742e145d12b3e49c9)

- I followed along with the [ImGui](https://www.youtube.com/watch?v=st4lgNI6_F4&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=15) video to hack ImGui into the project. As expected, I immediately ran into some... er... temporal issues because I'm watching from almost 4 years in the future. A lot of changes were made to ImGui since this video. IO has been completely revamped, for example. Fortunately, the old way was obsoleted but not removed<sup>3</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/49e6fee0ed67016ae4fff7728092e91e331af700)

- I intend to create a C# project called `Fargrid-Client` or something in the future. Specifically, when Cherno decides to convert Hazel to a static library, I will create an additional C++ CLI project to export to .NET. That's when things should start to get really interesting. Stay tuned.

###### footnotes

  <sup><sup>1</sup> I was using `FARGRID_API` for all my class definitions, but the actual macro is `FG_API`.</sup> :sweat_smile:

  <sup><sup>2</sup> I may want to investigate [Glad 2](https://gen.glad.sh/) later to see if there are any benefits to using it.</sup>

  <sup><sup>3</sup>  Unfortunately, all the key remapping code that Cherno just conveniently copied & pasted from the ImGui source was no long there, so I had to type all that out :unamused:
