#include <stdio.h>

struct student {
  int id;
  int value;
};

int main() {
  struct student var;

  printf("Value of id and value before initialization: %d %d\n", var.id, var.value);

  var = (struct student){20, 40};

  printf("Value of id and value after 1st initialization: %d %d\n", var.id, var.value);

  var.id = 12;
  var.value = 24; 

  printf("Value of id and value after 2nd initialization: %d %d\n", var.id, var.value);

  return 0;
}