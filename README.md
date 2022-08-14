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

  A continuing source of frustration is that compiler warnings for external includes keep appearing. The `/external:W0` compiler option doesn't seem to work. I either didn't configure it correctly for Premake, I don't completely understand how it's supposed to work, or it just plain doesn't work. I also discovered the [externalwarnings](https://premake.github.io/docs/externalwarnings/) option for Premake, but it just crashed Premake when I tried to use it. \*sigh\*

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

- I followed along with the [ImGui](https://www.youtube.com/watch?v=st4lgNI6_F4&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=15) video to hack [Dear ImGui](https://github.com/ocornut/imgui) into the project. As expected, I immediately ran into some... er... temporal issues because I'm watching from almost 4 years in the future. A lot of changes were made to ImGui since this video. IO has been completely revamped, for example. Fortunately, the old way was obsoleted but not removed<sup>3</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/49e6fee0ed67016ae4fff7728092e91e331af700)

- I followed along with the [ImGui Events](https://www.youtube.com/watch?v=yBP1gSbQPPM&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=16) video to hook the input events for Dear ImGui<sup>4</sup>. No problems at all.

  - [commit](https://github.com/toverbay/fargrid/commit/ab1d77a8df3aec10942a67e5ddde5a42bcdb552b)

- I followed along with the [Input Polling](https://www.youtube.com/watch?v=yuhNj8yGDJQ&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=19) video. No surprises. It all worked.

  - [commit](https://github.com/toverbay/fargrid/commit/1f50ce873280ed7177a4f0303f954e362b889c04)

- I followed along with the [Key and Mouse Codes](https://www.youtube.com/watch?v=zaJGn8pur5I&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=20) video. Basically took the key and mouse button codes from glfw and renamed them for the engine. I suppose any re-mapping code will be added later when we implement backends other than OpenGL.

  - [commit](https://github.com/toverbay/fargrid/commit/8fb519c224cc38bae67aad07f469bdc32b7195ac)

- I followed along with the [Maths](https://www.youtube.com/watch?v=Idr1G1KyPNg&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=21) to add [glm](https://glm.g-truc.net/0.9.2/api/index.html) to the library. I love math libraries and I'm excited to start using glm, but I kinda want to implement my own math library.<sup>5</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/f25d1e1152f95eee7f1c8b39eb6af833ac934974)

- I followed along with the [ImGui Docking and Viewports](https://www.youtube.com/watch?v=lZuje-3iyVE&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=22) video and I was surprised it went as smoothly as it did. There was a small problem where the folder to `imgui_impl_opengl3.cpp` and `imgui_impl_glfw.cpp` had changed since the video was published, but it wasn't too difficult to find them in their new folder (`backends` instead of `examples`). I actually anticipated some things that Cherno initially forgot to do, such as adding the `ImGuiLayer` to the stack and incrementing `m_LayerInsertIndex` after adding a layer. This episode was a lot of fun!

  - [commit](https://github.com/toverbay/fargrid/commit/b842c4d183de9d5b53aba493f8ded49ddc828e60)

- I followed along with the [Static Libraries and ZERO Warnings](https://www.youtube.com/watch?v=TlvmnoDlrI0&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=26) video to convert the project to a staic library and kind of clean up warnings and stuff. All went well. ~~This is the point where I'm going to try and introduce a CLI project to be able to bind to Fargrid from a C# project. I may even create a separate fork for this stuff so I can at least continue with the video series without getting hung up on the CLI binding.~~

  - [commit](https://github.com/toverbay/fargrid/commit/bd239ad2ebb0db444db1343578ed9aeb0e6b5cfe)

- I followed along with the [Rendering Context](https://www.youtube.com/watch?v=YZKEjaCnsjU&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=27) video to add a render or graphics context to the project. Not much changed as far as what it looks like when it runs, but it lays the foundation for abstracting away the specifics of each rendering framework (OpenGL, Vulkan, DirectX, Metal, etc).

  - [commit](https://github.com/toverbay/fargrid/commit/c439e93cf5fd07ba868f09153983ad670f354202)

- I followed along with the [Our First Triangle!](https://www.youtube.com/watch?v=bwFYXo0VgCc&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=28) video to render a triangle on the screen. Not much else to say... the triangle appeared in the window when I ran it...

  - [commit](https://github.com/toverbay/fargrid/commit/14e140d0da443ab0210bc19718a684ef3be9078e)

- I followed along with the [OpenGL Shaders](https://www.youtube.com/watch?v=QBCCHm_9HV8&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=29) video to add vertex & fragment shaders to the project.

  - [commit](https://github.com/toverbay/fargrid/commit/26090c9c1d90650fa210428c007731f5bf38cec4)

- I followed along with the [Renderer API Abstraction](https://www.youtube.com/watch?v=BwCqRqqbB1Y&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=30) video to add the foundation abstracting away the details of each renderer API *(OpenGL, DirectX, Vulcan, etc)*. Looks exactly the same as the previous commit during runtime, but now we can choose the implementation of vertex & index buffers based on the chosen Renderer API. Other abstractions will be added in later videos.

  - [commit](https://github.com/toverbay/fargrid/commit/8718e089d6d58d15a0b16173192096386725bad7)

- I followed along with the [Vertex Buffer Layouts](https://www.youtube.com/watch?v=jIJFM_pi6gQ&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=31) video to add an elegant way to specify the layout of vertex buffers. I quite enjoyed this one, although I had to deal with one small issue<sup>6</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/c88cc34aaa676ae803c9ee67d58f5faa258e34e4)

- I followed along with the [Vertex Arrays](https://www.youtube.com/watch?v=rkxrw8dNrvI&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=32) video to implement API-agnostic vertex arrays. I started pausing the video to try to implement the code before Cherno did. Worked out well. I'm definitely getting more comfortable writing this kind of code. I even anticipated some things before he did in the video. I'm still having a lot of fun with this.

  - [commit](https://github.com/toverbay/fargrid/commit/2687a80e7a9f88b53e277b91d13acef35cc04b5f)

- I followed along with the [Renderer Flow and Submission](https://www.youtube.com/watch?v=akxevYYWd9g&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=33) video to implement the API-agnostic `RenderCommand` and `RendererAPI` classes (and the OpenGL implementation). Saw an interesting comment about using the `final` keyword on sub-classes as sort of a mini optimization<sup>7</sup>. Also, I really hate the function name `Submit`<sup>8</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/4b4d46b4c1d31f502f7edfc8b9fd2fd41f452689)

- I followed along with the [Creating an Orthographic Camera](https://www.youtube.com/watch?v=NjKv-HWstxA&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=35) video to implement an orthographic camera. I had a moment of confusion when I tried to be clever and add `near` and `far` parameters with default values to the constructor. This is trivial to do in C#, but apparently in C/C++, the signature defined in the header cannot be the same as the signature in the definition. That took a few minutes of frustrated Googling to figure out. I also had a small moment of satisfaction when I immediately figured out why he was getting a blank screen after he commented out the code to set the camera position. I changed the names in a few places to make things more obvious<sup>9</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/fcb7c05b0064df9cf3b73e190991bb72eabd49dd)

- I followed along with the [Moving to Sandbox](https://www.youtube.com/watch?v=4zj-0FQ7Xbg&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=36) video to move code from the Application to the Sandbox app. Again, I paused the video after Cherno announced what he planned to do, then wrote the code before resuming the video. I'm definitely getting more comfortable with this.

  - [commit](https://github.com/toverbay/fargrid/commit/8fdb00fccd9ef4876ccc2a36c968f94b44ec21e4)

- I followed along with the [TIMESTEPS and DELTA TIME](https://www.youtube.com/watch?v=pctGOMDW-HQ&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=37) video to add a rather primitive timing mechanism to the engine. Cherno did mention that more functionality will be added to it later, but I couldn't help thinking about an [old blog post](https://gafferongames.com/post/fix_your_timestep/) I read about timing in games, particularly with game physics. Rendering should go as fast as the monitor's refresh rate (to avoid tearing), but physics integration frames should run at a predictable (and often slower) rate. For now, I'm going to trust that Cherno knows what he's doing, but I will re-visit this later<sup>10</sup>.

  - [commit](https://github.com/toverbay/fargrid/commit/2b1658f2506bf51287b5e2b58f63d473cacd0886)

- I followed along with the [Transforms](https://www.youtube.com/watch?v=cbB2fh0UxZ0&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=38) video to add transforms that allow objects in the scene to have their own translation, rotation, and scale. We used this to draw a grid of squares on the screen, which is basically a tilemap without the textures. Very cool.

  - [commit](https://github.com/toverbay/fargrid/commit/f528052996b9f9907a8a2b7ed768e7d4230676b2)

- I followed along with the [Material Systems](https://www.youtube.com/watch?v=2k5FjtMNQsM&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=39) video where Cherno explained material systems. He didn't actually implement a material system in the video. Instead, he added the ability to upload & use a color in a shader. Not terribly useful yet, but I did modify his code slightly to draw a checkerboard pattern.

  The more interesting thing about this video is at the very end when he put forth the question to continue the series as a fully 3D engine or switch to a "blazingly fast" 2D engine. Having watched the later videos, I know the decision was made to go 2D. I'm interested in making a 2D game, so I was ok with that. However, I wonder if maybe the better decision was to continue in 3D to teach all the aspects of a game engine rather than the more narrowly-focused 2D. I mean, 2D is just a subset of 3D, right? Sure, there are optimizations that are specific to 2D rendering, but I feel those could be taught as separate videos within the overall series. The sponsored version of his game engine is fully 3D and I intend on sponsoring him to get access to it, so I suppose it's not that big of a deal. Anyways...

  - [commit](https://github.com/toverbay/fargrid/commit/97bc1faf899dcc927604e3121c7fb654c72e630c)

- I followed along with the [Shader Abstraction and Uniforms](https://www.youtube.com/watch?v=d5wL6eZnWMU&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=40) video to move more OpenGL code from the shader class to the platform-specific implementation. More work needs to be done with other systems before we can really make the shader class abstract. He mentioned an optimization by caching the uniform locations with a hashmap and pointed to another [video in his OpenGL series](https://www.youtube.com/watch?v=nBB0LGSIm5Q) to do that. I think I'll watch that video and add it to Fargrid as well.

  - [commit]()

- ~~I intend to create a C# project called `Fargrid-Client` or something in the future. Specifically, when Cherno decides to convert Hazel to a static library, I will create an additional C++ CLI project to export to .NET. That's when things should start to get really interesting. Stay tuned.~~
- I looked ahead at future episodes and saw that Cherno intends on adding C# scripting support. Instead, I thought I'd try creating a version of this game engine written in **[Odin](https://odin-lang.org/)**.

###### footnotes

  <sup><sup>1</sup> I was using `FARGRID_API` for all my class definitions, but the actual macro is `FG_API`.</sup> :sweat_smile:

  <sup><sup>2</sup> I may want to investigate [Glad 2](https://gen.glad.sh/) later to see if there are any benefits to using it.</sup>

  <sup><sup>3</sup> Unfortunately, all the key remapping code that Cherno just conveniently copied & pasted from the ImGui source was no longer there, so I had to type all that out</sup> :unamused:

  <sup><sup>4</sup> The [FAQ](https://github.com/ocornut/imgui/blob/master/docs/FAQ.md#q-what-is-this-library-called) for the "imgui" library specifically states the name of the library is "Dear ImGui" (not ImGui or IMGUI).</sup>

  <sup><sup>5</sup> Easy to add to Fargrid, but this may get tricky to expose to C# later.</sup>

  <sup><sup>6</sup> In `Application.cpp` inside the element loop for the layout, casting the element offset to a void pointer `(const void*)element.Offset` caused a [C4312 warning](https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4312). After a bit of Googling, it seems like it's easy to fix with a double cast `(const void*)(UINT_PTR)element.Offset`.</sup>

  <sup><sup>7</sup> I tried it and... it works... not sure if it's any faster, but it didn't crash</sup>

  <sup><sup>8</sup> Maybe `Commit` or `Deliver` or simply `Render`? I'll have to figure out a better name.</sup>

  <sup><sup>9</sup> Like `SetRotationZ` instead of just `SetRotation` and `m_RotationZDeg` instead of `m_Rotation`. Probably makes it less readable... might change it back...</sup>

  <sup><sup>10</sup> The most popular comment from the video also mentions this, so I'm not alone thinking about this.</sup>
