#include <stdio.h>

int main() {
  int x = 15;
  const int *const ptr = &x;
  printf("Value of x: %d\n", *ptr);

  int a = 45;
  // ptr = &a;
  printf("Value of a: %d\n", *ptr);
}