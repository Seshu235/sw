#include <stdio.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int *ptr1 = &arr[0];
  int *ptr2 = ptr1 + 3;

  printf("%d %d ", *ptr1, *ptr2);

  printf("%ld ", ptr2 - ptr1);  // Difference gives the number of elements between two pointers
}