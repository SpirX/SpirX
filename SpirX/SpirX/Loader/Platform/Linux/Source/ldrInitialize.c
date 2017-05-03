//===========================================================================//
//                 .d8888b.           d8b         Y88b   d88P                //
//                d88P  Y88b          Y8P          Y88b d88P                 //
//                Y88b.                             Y88o88P                  //
//                 "Y888b.   88888b.  888 888d888    Y888P                   //
//                    "Y88b. 888 "88b 888 888P"      d888b                   //
//                      "888 888  888 888 888       d88888b                  //
//                Y88b  d88P 888 d88P 888 888      d88P Y88b                 //
//                 "Y8888P"  88888P"  888 888     d88P   Y88b                //
//                           888                                             //
//                           888                                             //
//                           888                                             //
//---------------------------------------------------------------------------//
// SpirX - A Layered Game Engine                            Polaritech, Inc. //
//---------------------------------------------------------------------------//
//                See https://doc.spirx.io for documentation.                //
//---------------------------------------------------------------------------//
// MIT License                                                               //
//                                                                           //
// Copyright (c) 2017 - Adrian J. Collado                                    //
//                                                                           //
// Permission is hereby granted, free of charge, to any person obtaining a   //
// copy of this software and associated documentation files (the "Software") //
// to deal in the Software without restriction, including without limitation //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,  //
// and/or sell copies of the Software, and to permit persons to whom the     //
// Software is furnished to do so, subject to the following conditions:      //
//                                                                           //
// The above copyright notice and this permission notice shall be included   //
// in all copies or substantial portions of the Software.                    //
//                                                                           //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS   //
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF                //
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN //
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,  //
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR     //
// OTHERWISE, ARISING FROM, OUT OF OR IN CONJUNCTION WITH THE SOFTWARE OR    //
// THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                //
//===========================================================================//
#include <spirx/spirx.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <elf.h>

extern int ldrGetExportList(
		const char*                             name,
		char**                                  symbols,
		struct SxMemoryCallbacks*               memoryCallbacks
);

uint32_t                                        ldrExportCount;
struct SxExportDescriptor*                      ldrExports;

struct LdrLibraryNode {
		char*                                   Name;
		struct SxExportDescriptor*				Exports;
		struct ldrLibraryNode*                  Next;
};

struct LdrLibraryNode*                          ldrLibraries;

int ldrInitialize(
		struct SxMemoryCallbacks* memoryCallbacks
) {
	ldrExportCount = 0;
	// struct LdrLibraryNode* libraries;
	// struct LdrLibraryNode* curLibrary;
	// if (memoryCallbacks != NULL) {
	// 	libraries = memoryCallbacks->Alloc(
	// 			memoryCallbacks->Data,
	// 			sizeof(struct LdrLibraryNode),
	// 			16
	// 	);
	// }
	// else {
	// 	libraries = malloc(
	// 			sizeof(struct LdrLibraryNode)
	// 	);
	// }
	// curLibrary = libraries;
	
	// curLibrary->Name = "libspirx.so";
	// curLibrary->Next = NULL;
	// curLibrary = curLibrary->Next;

	// Read Local Manifest
	
	// Read User Manifest
	
	// Read System Manifest

	if (ldrGetExportList("libspirx.so", NULL, NULL) != 0) {
		return 2;
	}

	void* sxLibrary = dlopen("libspirx.so", RTLD_NOW);
	if (sxLibrary == NULL) return 1;

	PFN_sxQueryExports sxLibQueryExports = dlsym(
			sxLibrary,
			"sxQueryExports"
	);
	if (sxLibQueryExports == NULL) return 1;
	ldrExportCount++;

	PFN_sxQueryAddress sxLibQueryAddress = dlsym(
			sxLibrary,
			"sxQueryAddress"
	);
	if (sxLibQueryAddress == NULL) return 1;
	ldrExportCount++;
	
	if (memoryCallbacks != NULL) {
		ldrExports = memoryCallbacks->Alloc(
				memoryCallbacks->Data,
				sizeof(struct SxExportDescriptor) * ldrExportCount,
				16
		);
	}
	else {
		ldrExports = malloc(
				sizeof(struct SxExportDescriptor) * ldrExportCount
		);
	}

	ldrExports[0] = (struct SxExportDescriptor) {
		"sxQueryExports",
		sxLibQueryExports
	};

	ldrExports[1] = (struct SxExportDescriptor) {
		"sxQueryAddress",
		sxLibQueryAddress
	};

	return 0;
}
