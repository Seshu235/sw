#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;
  const int *ptr = &a;  //  pointer to a const variable
  printf("Value of a: %d\n", *ptr);

  // Changing the value of the pointed location
  // *ptr = &b;  // Error: Cannot modify the value pointed by ptr
  printf("Value of a: %d\n", *ptr);

  // Changing the address of the pointer
  ptr = &b;
  printf("Value of b: %d\n", *ptr);
}