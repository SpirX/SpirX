+++
date = "2017-01-27T14:25:58-05:00"
title = "An Intro to Solum"

+++
<sub><sup>*Note: This post was migrated from [rcos.io](https://rcos.io/projects/polaritech/solum/blog).*<sup><sub>

Solum is a simple rendering engine written in C++ designed to allow runtime swapping of rendering drivers (i.e., OpenGL → DirectX 11 → Vulkan). This allows developers to experiment with various rendering backends without much setup work on their part. It utilizes modern C++ features and compiles with tools later than G++ 6 and MSVC 2017.

The reasoning behind writing a rendering engine with this functionality is to explore various rendering techniques across multiple platforms. It also allows with experimentation of features specific to a particular backend.

The proposal for Solum can be found on [our GitHub](https://github.com/Polaritech/Solum/blob/master/Documentation/Proposals/RCOS-Spring2017.md).
