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

    // When the calculation is hardcoded and inline like this,
    // the compiler will do the whole calculation at compile time
    // and optimize away the DIVF32 instruction.
    // By doing the calculation at compile time (and hence not on the TMS),
    // we get the correct result
    // float inlineCalc = 480.0 * (100.0 + 8.0) / 100.0;
    float inlineCalc = 51840.0 / 100.0;

    // By separating out the last divide operation, we force
    // the compiler to do the calculation on the TMS with the DIVF32 instruction.
    // This particular set of values happens to give an incorrect result
    // of 518.39996 (0x44019999).
    // Note that all of (518.4, 51840, 100) are values that can be represented
    // exactly in 32 bit floating point, this is not an issue with precision
    // - 518.4 = 0x4401999A
    // - 51840 = 0x474A8000
    // - 100   = 0x42C80000
    // float divSeparate = 480.0 * (100.0 + 8.0);
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
