#include <stdio.h>
#include <stdlib.h>

int main() {
  int **ptr = NULL;
  int rows = 0;
  int cols = 0;

  printf("Enter the number of rows and columns of matrix\nEx: rows: 3 cols: 3\n");
  printf("rows: ");
  scanf("%d", &rows);
  printf("cols: ");
  scanf("%d", &cols);

  ptr = malloc(rows * sizeof(int *));
  if (ptr == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < rows; i++)
  {
    ptr[i] = malloc(cols * (sizeof(int *)));
    if (ptr[i] == NULL) {
      perror("col-malloc");
      exit(EXIT_FAILURE);
    }
  }

  printf("Enter matrix elements\n");
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      printf("A[%d][%d]=", i+1, j+1);
      scanf("%d", &ptr[i][j]);
    }
  }

  printf("Matrix elements\n");
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      printf("%d ", ptr[i][j]);
    }
    printf("\n");
  }

  return 0;  
}