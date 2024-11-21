#include <stdio.h>
#include <stdint.h>

int main() {
  int16_t num = 0;

  printf("Enter a interger in the range 0 to 255\n");
  scanf("%hd", &num);

  printf("%c", 0x0A);

  for (size_t i = 0; i < num; i++)
  {
    for (size_t j = 0; j <= i; j++)
    {
      printf("%c", 0x2A);
    }
    printf("%c", 0x0A);
  }
  
  return 0;
}