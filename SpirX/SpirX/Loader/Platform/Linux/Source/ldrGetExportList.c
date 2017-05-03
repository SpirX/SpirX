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
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <elf.h>

int ldrGetExportList(
		const char*                             name,
		char**                                  symbols,
		struct SxMemoryCallbacks*               memoryCallbacks
) {
	int libId = open(name, O_RDONLY);
	if (libId < 0) {
		return libId;
	}

	struct stat libStat;
	fstat(libId, &libStat);

	char* libBlock = mmap(
			NULL,
			libStat.st_size,
			PROT_READ,
			MAP_SHARED,
			libId,
			0
	);
	if (libBlock == MAP_FAILED) {
		close(libId);
		return 1;
	}

	for (size_t i = 0; i < libStat.st_size; i += 16) {
		printf("%-8zX:", i);
		for (size_t j = 0; j < 16; j++) {
			printf("  %02X", (libBlock[i + j]) & 0xFF);
		}
		printf("\n");
	}

	const char magic[] = { 0x7F, 'E', 'L', 'F' };
	Elf64_Ehdr* header = (Elf64_Ehdr*)(libBlock);
	if (memcmp(header->e_ident, magic, 4) != 0) {
		return 1;
	}



	return 0;
}
