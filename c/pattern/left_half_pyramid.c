#include <stdio.h>

int main() {
  int num = 0;
  printf("Enter an integer\n");
  scanf("%d", &num);

  printf("\n");

  for (size_t i = 0; i < num; i++)
  {
    for (size_t k = 0; k < num - i - 1; k++)
    {
      printf(" ");
    }
    for (size_t j = 0; j < i + 1; j++)
    {
      printf("%c", 0x2A);
    }

    printf("%c", 0x0A);    
  }
  
}