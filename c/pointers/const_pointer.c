#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;
  int *const ptr = &a;  //  const pointer pointing to normal variable

  printf("Value of a: %d\n", *ptr);

  // Changing the value of the pointed location
  *ptr = b;
  printf("Value of a: %d\n", *ptr);

  // Changing the address of the pointer
  // ptr = &b; // Error: Cannot change the address of a constant pointer
  printf("Value of b: %d\n", *ptr);
}