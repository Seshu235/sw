#include <stdio.h>
#include <stdlib.h>

[[noreturn]] void show()
{
  printf("BYE BYE\n");
  // return 10;
}

int main(void) {
  printf("Ready to begin...\n");

  show();

  printf("Not over till now\n");
  return 0;
}