#include "main.h"
#include <stdio.h>
/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
    unsigned int n;

    n = binary_to_uint("1");
    printf("%u\n", n);
    n = binary_to_uint("101");
    printf("%u\n", n);
    n = binary_to_uint("1e01");
    printf("%u\n", n);
    n = binary_to_uint("1100010");
    printf("%u\n", n);
    n = binary_to_uint("0000000000000000000110010010");
    printf("%u\n", n);
    n = binary_to_uint("1000000000000010000000000000000010");
    printf("%u\n", n);
    n = binary_to_uint("100010000001000000110010010");
    printf("%u\n", n);
    n = binary_to_uint("00000000c00000010000110010010");
    printf("%u\n", n);
    n = binary_to_uint("0000x0e0000e0000000000110010010");
    printf("%u\n", n);
    n = binary_to_uint("00000b00000000000000110010010");
    printf("%u\n", n);
    n = binary_to_uint("00000010000000000000110010010");
    printf("%u\n", n);
    n = binary_to_uint("00000002000000000000110010010");
    printf("%u\n", n);
    n = binary_to_uint("00000000400000000000110010010");
    printf("%u\n", n);
    n = binary_to_uint(NULL);
    printf("%u\n", n);
    return (0);
}
