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

void swap(int *ptr1, int *ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

void selection_sort(int arr[], size_t length) {
  int min_index;
  
  for (size_t i = 0; i < length-1; i++)
  {
    min_index = i;
    for (size_t j = i+1; j < length; j++)
    {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    swap(&arr[i], &arr[min_index]);    
  }  
}

void printArray(int arr[], size_t length) {
  for (size_t i = 0; i < length; i++)
  {
    printf("%d ", arr[i]);
  }  
}

int main() {
  int arr[MAX_SIZE] = {0};
  
  getRandInput(arr, MAX_SIZE);

  printf("before sorting...\n");
  printArray(arr, MAX_SIZE);

  selection_sort(arr, MAX_SIZE);

  printf("\nafter sorting...\n");
  printArray(arr, MAX_SIZE);

  return 0;
}