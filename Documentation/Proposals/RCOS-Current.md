# SpirX ~ A Simple Rendering Engine
SpirX is a layered game engine designed from the ground up for runtime extensibility. It allows runtime swapping of components, as well as feature discovery from layers and extensions. It utilizes a C interface as to remain portable and usable from any programming language with the ability to call C functions.

## Goals
### Implement an Extension and Layer Loader
To allow additional functionality to be loaded into the application, a loader must me implemented.
#### Features
- [X] Open shared libraries on Linux
- [ ] Open shared libraries on Windows
- [X] Extract function pointers from SpirX core libraries
- [ ] Extract function pointers from layers and extensions
- [X] Create a call chain from given function pointers
- [ ] Patch executable code with function call chain entry points

### Design a Windowing Interface
To allow cross platform rendering, a windowing interface is essential. It allows applications to output to the screen, as well as recieve messages from the operating system (such as input messages).
#### Features
- [ ] Windows using the Win32 API
- [ ] Linux using Xlib
- [X] Linux using XCB

### Design a Rendering Interface
One of the primary goails of this project is to allow rendering (as would be expected in a game engine). Support for various backends will be supported through extensions.
#### Features
- [ ] DirectX
  - [ ] Version 11
- [ ] OpenGL
  - [ ] Version 3.3 Core
- [ ] Vulkan

## Roadmap
SpirX is in an early state, and requires quite a bit of work to get to a usable state. Our timeline from when the project was restarted (4.24.2017) is as follows:
- 04.24.2017 **Project Re-Written**
- 04.27.2017 **Loader: Open Shared Libraries**
- 04.29.2017 **Loader: Core Function Extraction**
- 04.30.2017 **Loader: Call Chain Creation**

## Administration
Our team currently consists of [Adrian J. Collado](https://github.com/AdrianCollado) and [Nicholas Fogg](https://github.com/Exxion).

Adrian has the following responsibilities:
- Project & Team Management
- Engine Development

Nick has the following responsibilities:
- Engine Development

Developers will work on individual [issues](https://github.com/SpirX/SpirX/issues), working towards the completion of a [milestone](https://github.com/SpirX/SpirX/milestones). Issues will be managed using [issue boards](https://github.com/SpirX/SpirX/boards).

Each set of commits that are used to complete a particular issue will follow the guidelines found in the [contribution guidelines](https://github.com/SpirX/SpirX/blob/master/CONTRIBUTING.md). Code will be formatted according to the [style guidelines](https://github.com/SpirX/SpirX/blob/master/Documentation/StyleGuide.md).

