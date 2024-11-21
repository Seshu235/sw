#include <stdio.h>
#include <stdbit.h>

int main() {
    unsigned short int num = 0b00001111; // Initialize a number with some bits set

    printf("%d\n", stdc_count_ones(num));
    printf("%d\n", stdc_count_zeros(num));

    // Set the 5th bit (index 4)
    printf("After setting 5th bit: %u\n", num); // Output: 31 (0b00011111)

    // Clear the 3rd bit (index 2)
    printf("After clearing 3rd bit: %u\n", num); // Output: 27 (0b00011011)

    // Toggle the 1st bit (index 0)
    printf("After toggling 1st bit: %u\n", num); // Output: 26 (0b00011010)

    return 0;
}