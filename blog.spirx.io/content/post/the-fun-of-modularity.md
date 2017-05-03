+++
date = "2017-03-05T21:06:11-05:00"
draft = false
title = "The Fun of Modularity"

+++
<sub><sup>*Note: This post was migrated from [rcos.io](https://rcos.io/projects/polaritech/solum/blog).*<sup><sub>

Over the course of development so far (and through other projects), I've found that C++ is not the most modular programming language once you leave the safety of a single executable. Once you decide to split up components into separate libraries, things begin to fall apart.

The problem lies in the very definition and standardization of C++. The developers of the standard, with regard to backwards compatibility, define C++ to *not* have any specified ABI (application binary interface). This makes sense when you think about code written in C++ running on multiple platforms, each with varying ABIs. This might seem fine, until you realize that since there are separate ABIs per platform, there must be different compiler ABIs. GCC, Clang, and Microsoft Visual C++ all have different ABIs. Sometimes their ABI changes between releases, breaking things further.

A common solution for this problem is to use plain old C for working across process boundaries (think *.exe* ⇒ *.dll*), and then use pure interfaces for C++ classes. Simply make a function called `MyClass_Create` that creates concrete instances of your interface. This gains you portability across your compiler, but what about using libraries compiled from a different compiler? They might use a different format for their *vtables*, which are structures that facilitate dynamic dispatch. Many more problems exist as well, and once again, everything falls apart.

The solution for this isn't so simple. You could work solely with composition rather than inheritance, but you do lose some flexibility and are forced to write extra unnecessary code. You could alternatively compile your code with multiple compilers and have the end user select the correct type, though we all know end users are *fantastic* at doing things correctly. A final alternative is to not use C++ at all, but rather use something like plain C instead.

I've decided for the moment to do something else entirely: not split up my code into separate libraries. Binary modularity can be a problem for another day.
