#include <stdio.h>
#include <limits.h>

/**
 * hello.c
 */
void print_hex(const void* ptr, size_t size) {
    const unsigned char* bytes = (const unsigned char*)ptr;
    size_t i;
    for(i = 0; i < size; ++i) {
        printf("%04x ", bytes[i]);
    }
    printf("\n");
}

int main(void)
{

    // float inlineCalc = 480.0 * (100.0 + 8.0) / 100.0;
    // float divSeparate = 480.0 * (100.0 + 8.0);
    float inlineCalc = 51840.0 / 100.0;
    float divSeparate = 51840.0;
    divSeparate /= 100.0;
    printf("\n");
    printf("bits in char: %d\n", CHAR_BIT);
    printf("sizeof float: %zu\n", sizeof(divSeparate));
	printf("inlineCalc: %a\n", inlineCalc );
	printf("divSeparate: %a\n", divSeparate );
	printf("inlineCalc: "); print_hex(&inlineCalc, sizeof(inlineCalc));
	printf("divSeparate: "); print_hex(&divSeparate, sizeof(divSeparate));
	printf("equal: %d\n", inlineCalc == divSeparate);

	for(;;);
	return 0;
}
