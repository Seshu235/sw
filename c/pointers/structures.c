#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
  int id;
  char name[128];
};

int main() {
  struct employee *ptr = NULL;
  int num = 0;

  printf("Enter the number of employees: ");
  scanf("%d", &num);

  ptr = (struct employee *)malloc(num * sizeof(struct employee));
  if (ptr == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < num; i++)
  {
    printf("\nEnter Employee %ld details\nId: ", i+1);
    scanf("%d", &ptr[i].id);
    getchar();
    printf("Name: ");
    fgets(ptr[i].name, 128, stdin);
    ptr[i].name[strcspn(ptr[i].name, "\n")] = '\0';
  }

  for (size_t i = 0; i < num; i++)
  {
    printf("\nEmployee %ld details\n", i+1);
    printf("Id: %d Name: %s\n", ptr[i].id, ptr[i].name);
  }
  
  
}