#include <stdio.h>
#include <stdlib.h>

struct var {
  int value;
};

void display(struct var *ptr) {
  printf("Address: %p\n", ptr);
  ptr->value = 34;
}
int main() {
  struct var *ptr = (struct var *)malloc(sizeof(struct var));
  printf("Address: %p\n", ptr);
  ptr->value = 45;

  display(ptr);

  printf("value: %d\n", ptr->value);

  return 0;
}