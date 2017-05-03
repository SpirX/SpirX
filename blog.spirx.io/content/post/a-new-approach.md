+++
date = "2017-05-01T02:53:26-05:00"
title = "A New Approach"

+++
While I was originally working on ~~Solum~~ SpirX, I had difficulty figuring out how to have an extensible interface so that I could offload some of the work that the engine would be doing to external libraries. However, working with C++ to do so proved very difficult, and I eventually came to the conclusion that I would have to ditch C++ for the project's interface (although internal code can still be written in C++).

As a result, I was left thinking about how I would define a nice C interface for the project. I went through a few approaches, and finally settled on an interface similar to the Vulkan API.

Vulkan's API is very simple, and is designed from the ground up for extensibility. Rather than implementing all of the diagnostics and overlays into the API itself, it builds itself up with the concept of *layers*. Layers are essentially intercepts for functions that are loaded at runtime. This means that you only pay for the diagnostics when you need them, and can drop them once you've fully debugged your application.

Vulkan also has support for extensions, which rather than intercept existing function calls, extensions add new function calls. This allows for extending Vulkan's functionality with features such as the *Window System Interface (WSI)*.

Being a game engine, ~~Solum~~ SpirX is well suited for a layered and extensible approach. Each core module, such as graphics, physics, and neworking, can all be treated as their own individual extensions. Diagnostics and debugging layers can be built on-top of them. This both keeps the engine very modular by design, and should help speed up development as someone working on physics should not even have to ever see the graphics code.

The implementation of the core system, as well as the process of loading layers and extensions is, however, not as easy as expected. While ~~Solum~~ SpirX can currently load functions from layer shared libraries and create chains of function calls for each API function, it does not do so in a way that I feel will be the most performant. Currently, the implementation will open a library and load the relevant functions into a linked list of functions for each API function. Each function is then called one after another when needed.

Ideally, the implementation will lookup the import table, as well as the relocation table of the application at startup, and patch the relevant addresses directly into the code, eliminating a linked list lookup, and the initial function call into the loader stub. Right now a linked list works fine as I'm not too concerned with the current performance (especially due to the small size of the codebase).

I also need to implement the loading of extensions, which will come after I add library manifests for layers and extensions. Manifests will act as a mapping for functions, as well as general information about the loaded extension or layer. Currently, without a list of functions that an extension provides, I cannot load the necessary data (although this could be circumvented by parsing the loaded library header, which would be needed for the ideal implementation discussed earlier).

Although ~~Solum~~ SpirX has changed a lot from its C++ origins, I feel that it will progress more smoothly now due to its refined architecture.
