+++
date = "2017-03-20T15:28:32-05:00"
draft = false
title = "Flawed from the Start"

+++
<sub><sup>*Note: This post was migrated from [rcos.io](https://rcos.io/projects/polaritech/solum/blog).*<sup><sub>

I recently started redesigning Solum due to the discovery that the structure of the software was not designed as efficiently as I thought.

Both the DirectX 11 and Vulkan backends were written for the software, so I decided to do a bit of profiling to see how much faster Vulkan would perform than DirectX. The results were disappointing.

In the tests that I ran, Vulkan was only marginally faster on the test cases. Similar test cases that I had seen done separately with DirectX and Vulkan showed a larger gap in performance. I started digging into the software, and discovered that making both backends conform to the same API was the problem. The result was that the DirectX backend was slightly convoluted in terms of code, and that the Vulkan backend lost the explicit control over the GPU that gave it such a performance boost.

I thus had to start working on redesigning Solum to fix this problem. The original idea behind Solum was to write a library that allowed me to work with, test, and change between different graphics APIs while the program is running. My thought was that consistent, swappable components would make this possible. However, each API is different in such a way that a consistent component lowers each API's functionality. My fix for this is to reduce the library user's control over the intricacies of the underlying graphics API's, and not expose separate components for the APIs themselves. I can thus internally do the work required to make each implementation as fast (and efficient) as possible.

My current work is rewriting the proposal and refactoring the code that can be salvaged from the project. We'll see where it goes from there.
