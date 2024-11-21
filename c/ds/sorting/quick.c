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

int partition(int arr[], size_t low_index, size_t high_index) {
  int pivot = arr[low_index];
  int local_index = low_index;

  for (int i = low_index+1; i < high_index; i++) {
    if (arr[i] < pivot) {
      swap(&arr[i], &arr[local_index]);
      local_index++;
    }
  }

  swap(&pivot, &arr[local_index]);

  return local_index;
}

void quick_sort(int arr[], size_t low_index, size_t high_index) {
  if (low_index < high_index) {
    int pivot = partition(arr, low_index, high_index);
    quick_sort(arr, low_index, pivot);
    quick_sort(arr, pivot+1, high_index);
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

  printf("\x1b[32mQuick Sort...\x1b[0m\n");
  
  getRandInput(arr, MAX_SIZE);

  printf("\x1b[33mBefore sorting...\x1b[0m\n");
  printArray(arr, MAX_SIZE);
  
  quick_sort(arr, 0, MAX_SIZE);

  printf("After sorting...\n");
  printArray(arr, MAX_SIZE);

  return 0;  
}