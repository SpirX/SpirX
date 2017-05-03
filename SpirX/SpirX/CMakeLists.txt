#=============================================================================#
#                 .d8888b.           d8b         Y88b   d88P                  #
#                d88P  Y88b          Y8P          Y88b d88P                   #
#                Y88b.                             Y88o88P                    #
#                 "Y888b.   88888b.  888 888d888    Y888P                     #
#                    "Y88b. 888 "88b 888 888P"      d888b                     #
#                      "888 888  888 888 888       d88888b                    #
#                Y88b  d88P 888 d88P 888 888      d88P Y88b                   #
#                 "Y8888P"  88888P"  888 888     d88P   Y88b                  #
#                           888                                               #
#                           888                                               #
#                           888                                               #
#-----------------------------------------------------------------------------#
# SpirX - A Layered Game Engine                            Polaritech, Inc.   #
#-----------------------------------------------------------------------------#
#                See https://doc.spirx.io for documentation.                  #
#-----------------------------------------------------------------------------#
# MIT License                                                                 #
#                                                                             #
# Copyright (c) 2017 - Adrian J. Collado                                      #
#                                                                             #
# Permission is hereby granted, free of charge, to any person obtaining a     #
# copy of this software and associated documentation files (the "Software"),  #
# to deal in the Software without restriction, including without limitation   #
# the rights to use, copy, modify, merge, publish, distribute, sublicense,    #
# and/or sell copies of the Software, and to permit persons to whom the       #
# Software is furnished to do so, subject to the following conditions:        #
#                                                                             #
# The above copyright notice and this permission notice shall be include in   #
# all copies or substantial portions of the Software.                         #
#                                                                             #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE #
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     #
# FROM, OUT OF OR IN CONJUNCTION WITH THE SOFTWARE OR THE USE OR OTHER        #
# DEALINGS IN THE SOFTWARE.                                                   #
#=============================================================================#
cmake_minimum_required(VERSION 3.6)

project(spirx-project
	VERSION 0.1.0
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE Debug)

#=============================================================================#
#                                   Library                                   #
#=============================================================================#
add_library(spirx SHARED
	"Source/spirx.c"
)

target_include_directories(spirx PUBLIC "Include")
target_include_directories(spirx PRIVATE "Source")

target_compile_definitions(spirx PRIVATE SX_EXPLICIT_LINK)

if (WIN32)

elseif (APPLE)

elseif (UNIX AND NOT APPLE)
	target_sources(spirx PRIVATE
		"Platform/Linux/Source/sxQueryAddress.c"
		"Platform/Linux/Source/sxQueryExports.c"
	)

	target_include_directories(spirx PRIVATE "Platform/Linux")
endif ()

#=============================================================================#
#                                   Loader                                    #
#=============================================================================#
add_library(spirx-loader SHARED
	"Loader/Source/spirx.c"
)

target_include_directories(spirx-loader PUBLIC
	"Include"
	"Loader/Include"
)
target_include_directories(spirx-loader PUBLIC "Loader/Source")

if (WIN32)

elseif (APPLE)

elseif (UNIX AND NOT APPLE)
	target_sources(spirx-loader PRIVATE
		"Loader/Platform/Linux/Source/sxQueryAddress.c"
		"Loader/Platform/Linux/Source/sxQueryExports.c"

		"Loader/Platform/Linux/Source/ldrInitialize.c"
		"Loader/Platform/Linux/Source/ldrGetExportList.c"
	)

	target_include_directories(spirx-loader PRIVATE "Platform/Linux")
	target_link_libraries(spirx-loader PRIVATE dl)
endif ()
#=============================================================================#
#                                    Tests                                    #
#=============================================================================#
add_executable(spirx-tests
	"Tests/main.c"
)

target_link_libraries(spirx-tests spirx-loader)
