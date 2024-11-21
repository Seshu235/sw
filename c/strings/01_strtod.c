#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *str1 = "123.456abc";
    const char *str2 = "3.14 is pi";
    const char *str3 = "not a number";
    char *endptr;

    // Convert first string
    double value1 = strtod(str1, &endptr);
    printf("Converted value from '%s': %f\n", str1, value1);
    printf("Stopped at: '%s'\n\n", endptr);

    // Convert second string
    double value2 = strtod(str2, &endptr);
    printf("Converted value from '%s': %f\n", str2, value2);
    printf("Stopped at: '%s'\n\n", endptr);

    // Convert third string
    double value3 = strtod(str3, &endptr);
    printf("Converted value from '%s': %f\n", str3, value3);
    printf("Stopped at: '%s'\n\n", endptr);

    return 0;
}