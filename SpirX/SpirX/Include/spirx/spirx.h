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
#ifndef SPIRX_H
#define SPIRX_H

#include <stddef.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define SX_MAX_NAME_SIZE 128
#define SX_MAX_EXPORT_SIZE 
#define SX_MAX_DESC_SIZE 128

//===========================================================================//
// Data Declarations                                                         //
//===========================================================================//

//===================================//
//               Memory              //
//===================================//
typedef void* (*PFN_sxAllocate)(
		void*                                   data,
		size_t                                  size,
		size_t                                  align
);
typedef void* (*PFN_sxReallocate)(
		void*                                   data,
		void*                                   memory,
		size_t                                  size,
		size_t                                  align
);
typedef void (*PFN_sxFree)(
		void*                                   data,
		void*                                   memory
);

struct SxMemoryCallbacks {
		void*                                   Data;
		PFN_sxAllocate                          Alloc;
		PFN_sxReallocate                        Realloc;
		PFN_sxFree                              Free;
};

//===================================//
//              Loading              //
//===================================//
struct SxExportDescriptor {
		char*                                   Name;
		void*                                   Export;
};

typedef int (*PFN_sxQueryExports)(
		uint32_t*                               count,
		struct SxExportDescriptor*              descriptors,
		struct SxMemoryCallbacks*               memoryCallbacks
);
typedef void* (*PFN_sxQueryAddress)(
		const char*                             name
);

//===================================//
//               System              //
//===================================//
struct SxSystem;
struct SxSystemLayerProperties {
		char*                                   Name;
		uint32_t                                SxVersion;
		uint32_t                                Version;
		char*                                   Description;
};

//===========================================================================//
// Explicitly Linked Declarations                                            //
//===========================================================================//
#if defined(SX_EXPLICIT_LINK)

//===================================//
//               Memory              //
//===================================//
void* sxAllocate(
		void*                                   data,
		size_t                                  size,
		size_t                                  align
);
void* sxReallocate(
		void*                                   data,
		void*                                   memory,

);
void sxFree(
		void*                                   data,
		void*                                   memory
);

//===================================//
//              Loading              //
//===================================//
int sxQueryExports(
		uint32_t*                               count,
		struct SxExportDescriptor*              descriptors,
		struct SxMemoryCallbacks*               memoryCallbacks
);
void* sxQueryAddress(
		const char*                             name
);

//===================================//
//               System              //
//===================================//

#endif




















struct SxWindow;
struct SxWindowInfo {
		int                                     Width;
		int                                     Height;
		int                                     X;
		int                                     Y;
		char*                                   Title;
};

typedef int (*PFN_sxCreateWindow)(
		const struct SxWindowInfo*              windowInfo,
		const struct SxMemoryCallbacks*         memoryCallbacks,
		struct SxWindow**                       window
);

typedef int (*PFN_sxDestroyWindow)(
		struct SxWindow*                        window
);

typedef int (*PFN_sxModifyWindow)(
		struct SxWindow*                        window,
		const struct SxWindowInfo*              windowInfo
);

typedef int (*PFN_sxAccessWindow)(
		struct SxWindow*                        window,
		struct SxWindowInfo*                    windowInfo
);

#if defined(__cplusplus)
}
#endif

#endif // SPIRX_H
