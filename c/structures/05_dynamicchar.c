#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char *str;
}student;

int main() {
  student *ptr = (student *)malloc(sizeof(student));
  if (ptr == NULL) {
    perror("malloc");
    return 1;
  }

  printf("Enter id: ");
  scanf("%d", &ptr->id);

  ptr->str = (char *)malloc(50*sizeof(char));
  if (ptr->str == NULL) {
    perror("malloc");
    return 1;
  }
  getchar();
  printf("Enter name: ");
  fgets(ptr->str, 50, stdin);
  ptr->str[strcspn(ptr->str, "\n")] = '\0';

  printf("student details\nid: %d\nname: %s\n", ptr->id, ptr->str);

  return 1;
}