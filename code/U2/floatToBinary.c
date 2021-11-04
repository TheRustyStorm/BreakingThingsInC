#include <stdio.h>
#include <stdint.h>

// https://github.com/TheRustyStorm/BreakingThingsInC

// 01000000010010010000111111010000
int main(int argc, char *argv[]) {
    // we create our floating point number
    float pi = 3.14159f; 
    // we interpret the memory as an uint32_t, as bitwise operations on floats/doubles are not allowed
    uint32_t *x = (uint32_t *)&pi;
    // we "copy" the content of x in y to work on this copy (more on that later)
    uint32_t y = *x;
    
    // we iterate from 0 to 8 * 4 (sizeof gives the size in bytes)
    for (int i = 0; i < 8 * sizeof(float); i++){
        // we want to get the MSB (Most Significant Bit) and create a mask that looks like this:
        // 10000000 00000000 00000000 00000000
        uint32_t mask = 1 << 31;
        // Bitwise AND of the mask and y gets us just an 1 or 0 in the position of the MSB
        uint32_t result = mask & y;
        // We shift our result back such that we either have a 1 or 0, instead of 2^32 or 0
        result = result >> 31;
        // We shift y to the left, such that the next bit will be in the position of the MSB
        y = y << 1;
        // We print an 1 or 0 with a trailing space
        printf("%i ",result);
    }
}
