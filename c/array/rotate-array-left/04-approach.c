// reversal algorithm
// time complexity O(n)
// space complexity O(1)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 10

void getRandInput(int arr[], int n)  {
  srand(time(NULL));

  for (size_t i = 0; i < n; i++)
  {
    arr[i] = rand() % 10;
  }  
}

void reverse(int *arr, int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

void rotatearr(int arr[], int n, int d) {
  d %= n;

  reverse(arr, 0, d-1);

  reverse(arr, d, n-1);

  reverse(arr, 0, n-1);
}

void display(int arr[], int n) {
  for (size_t i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[ARRAY_LEN] = {0};
  int d = rand() % 10;

  getRandInput(arr, ARRAY_LEN);

  printf("Reversal Algorithm\n");
  printf("left rotate array by %d positions\n", d);
  printf("before...\n");
  display(arr, ARRAY_LEN);

  rotatearr(arr, ARRAY_LEN, d);

  printf("after...\n");
  display(arr, ARRAY_LEN);

  return 0;
}