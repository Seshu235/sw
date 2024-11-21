#include <stdio.h>
#include <stdlib.h>

_Noreturn void Hello() {
  printf("Hello world!");
}

int main() {
  Hello();
  return 0;
}