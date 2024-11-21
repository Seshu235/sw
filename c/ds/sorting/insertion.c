#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void getRandInput(int arr[], size_t length) {
  srand(time(NULL));

  for (size_t i = 0; i < length; i++)
  {
    arr[i] = rand() % 20;
  }  
}

void swap(int *px, int *py) {
  *px ^= *py ^= *px ^= *py;
}

void insertion_sort(int arr[], size_t length) {
  // As there will be no left items present for array index 0
  // it is considered as sorted
  for (int i = 1; i < length; i++)
  {
    int j = i;
    while (j > 0 && arr[j-1] > arr[j])
    {
      swap(&arr[j], &arr[j-1]);
      j = j-1;
    }    
  }  
}

void printArray(int arr[], size_t length) {
  for (size_t i = 0; i < length; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[MAX_SIZE] = {0};

  getRandInput(arr, MAX_SIZE);

  printf("Before sorting...\n");
  printArray(arr, MAX_SIZE);

  insertion_sort(arr, MAX_SIZE);

  printf("\nAfter sorting...\n");
  printArray(arr, MAX_SIZE);

  return 0;
}