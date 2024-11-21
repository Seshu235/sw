#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
};

int main() {
  struct student *ptr = (struct student *)malloc(5*sizeof(struct student));
  if (ptr == NULL) {
    perror("malloc");
    return 1;
  }

  // Method 1
  for (size_t i = 0; i < 5; i++)
  {
    printf("Enter id for %ld student: ", i+1);
    scanf("%d", &(ptr + i)->id);
  }
  
  printf("\nPrinting after first reading...\n");
  for (size_t i = 0; i < 5; i++)
  {
    printf("Value of student id %ld is: %d\n", i+1, (ptr + i)->id);
  }

  // Method 2
  for (size_t i = 0; i < 5; i++)
  {
    printf("Enter id for %ld student: ", i+1);
    scanf("%d", &(*(ptr + i)).id);
  }
  
  printf("\nPrinting after first reading...\n");
  for (size_t i = 0; i < 5; i++)
  {
    printf("Value of student id %ld is: %d\n", i+1, (*(ptr + i)).id);
  }

  return 0;  
}