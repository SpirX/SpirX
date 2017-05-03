# SpirX ~ A Simple Rendering Engine
SpirX is a layered game engine designed from the ground up for runtime extensibility. It allows runtime swapping of components, as well as feature discovery from layers and extensions. It utilizes a C interface as to remain portable and usable from any programming language with the ability to call C functions.

The following proposal comes from when the project was called Solum, and as the entire project has changed drastically recently, a new proposal can be found [here](https://github.com/SpirX/SpirX/blob/master/Documentation/Proposals/RCOS-Current.md).

## Goals
### Implement a Windowing Interface
To allow cross platform rendering, a windowing interface is essential. It allows applications to output to the screen, as well as recieve messages from the operating system (such as input messages).
#### Features
- [X] Windows using the Win32 API.
- [X] X11 on Linux using either XCB and/or Xlib.

### Design a Rendering Interface
As the goal of this project is to experiment with rendering using multiple backends, a consistent rendering interface is extremely important. Features that are specific to a single backend will be exported as rendering extensions.
#### Features
- [X] DirectX
  - [X] Version 11
- [ ] OpenGL
  - [ ] Version 3.3 Core
- [X] Vulkan (Most)

### Design a Mathematics Interface
To assist with rendering, a linear algebra library is necessary. Having static objects is not as interesting as being able to transform and scale objects.
#### Features
- [ ] Vector Operations
- [ ] Matrix Operations
- [ ] Optimized Trigonometric Functions

### Design a User Input Interface
Receiving input from the user is a vital part of almost all applications. Controlling a scene using the keyboard or mouse will not only help with debugging but allow more control within an application.
#### Features
- [X] Keyboard
- [X] Mouse

### Stretch - Rendering Optimizations
Adding more support for certain rendering operations will allow developers to begin testing more advanced rendering techniques.

## Roadmap
SpirX is in an early state, and requires quite a bit of work to get to a usable state. Out current timeline for the first half of 2017 is as follows:
Our current timeline for the first half of 2017 is as follows:
- Milestone 0 **Setup**
  - 01.24.2017 **Proposal Written**
  - 01.27.2017 **Visual Studio Solution Created**
  - 01.31.2017 **Makefile Created**
  - 01.31.2017 **Build & Usage Instructions Written**
- Milestone 1 **Windowing**
  - 02.07.2017 **Windowing Interface Designed**
  - 02.10.2017 **Win32 Windowing Implemented**
  - 02.14.2017 **XCB Windowing Implemented**
  - 02.14.2017 **Xlib Windowing Implemented**
  - 02.17.2016 **Window Interface Documented**
- Milestone 2 **Basic Rendering**
  - 02.21.2017 **Rendering Interface Designed**
  - 02.28.2017 **DirectX 11 Initial Implemented**
  - 03.07.2017 **OpenGL 3.3 Initial Implemented**
  - 03.17.2017 **Vulkan Initial Implemented**
  - 03.21.2017 **Rendering Interface Documented**
  - 03.24.2017 **Renderer-Specific Documented**
- Milestone 3 **Mathematics**
  - 03.28.2017 **Mathematics Interface Designed**
  - 03.31.2017 **Vector Operations Implemented**
  - 03.31.2017 **Matrix Operations Implemented**
  - 04.04.2017 **Optimized Trigonometric Functions Implemented**
  - 04.04.2017 **Mathematics Interface Designed**
- Milestone 4 **User Input**
  - 04.07.2017 **Input Interface Designed**
  - 04.11.2017 **Keyboard (RawInput) Implemented**
  - 04.11.2017 **Mouse (RawInut) Implemented**
  - 04.14.2017 **Keyboard (XCB) Implemented**
  - 04.14.2017 **Mouse (XCB) Implemented**
  - 04.14.2017 **Keyboard (Xlib) Implemented**
  - 04.14.2017 **Mouse (Xlib) Implemented**
  - 04.18.2017 **Input Interface Documented**

## Administration
Our team currently consists of [Adrian J. Collado](https://github.com/AdrianCollado) and [Nicholas Fogg](https://github.com/Exxion).

Adrian has the following responsibilities:
- Project & Team Management
- Engine Development

Nick has the following responsibilities:
- Engine Development

Developers will work on individual [issues](http://git.polaritech.com/SpirX/SpirX/issues), working towards the completion of a [milestone](http://git.polaritech.com/SpirX/SpirX/milestones). Issues will be managed using [issue boards](http://git.polaritech.com/SpirX/SpirX/boards).

Each set of commits that are used to complete a particular issue will follow the guidelines found in the [contribution guidelines](http://git.polaritech.com/SpirX/SpirX/blob/master/CONTRIBUTING.md). Code will be formatted according to the [style guidelines](http://git.polaritech.com/SpirX/SpirX/blob/master/Documentation/StyleGuide.md).

