#include <spirx/spirx.h>

#include <stdio.h>

int main(int argc, char** argv) {
	struct SxExportDescriptor *exportArray;
	uint32_t exportCount;

	int res = sxQueryExports(&exportCount, NULL, NULL);
	if (res != 0) {
		printf("Export Error!\n");
		return res;
	}
	printf("Exported Symbols: %d\n", exportCount);
}
