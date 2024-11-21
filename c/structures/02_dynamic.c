#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
};

int main() {
  struct student *ptr = (struct student *)malloc(sizeof(struct student));
  if (ptr == NULL) {
    perror("malloc");
    return -1;
  }

  printf("Enter id: ");
  scanf("%d", &ptr->id);

  printf("Value after First scan: %d\n", ptr->id);

  printf("Enter id: ");
  scanf("%d", &(*ptr).id);

  printf("Value after second scan: %d\n", (*ptr).id);
}