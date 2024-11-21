// Native approach 
// time complexity O(n*d)
// space complexity O(1)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LEN 10

void getRandInput(int arr[], int n) {
  srand(time(NULL));

  for (size_t i = 0; i < n; i++)
  {
    arr[i] = rand() % 10;
  }  
}

void rotatearr(int arr[], int n, int d) {
  d %= n;

  for (size_t i = 0; i < d; i++)
  {
    int first = arr[0];
    for (size_t j = 0; j < n-1; j++)
    {
      arr[j] = arr[j+1];
    }
    arr[n-1] = first;
  }  
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

  printf("Naive Approach rotate one by one\n");
  printf("left rotate array by %d positions\n", d);
  printf("before...\n");
  display(arr, ARRAY_LEN);

  rotatearr(arr, ARRAY_LEN, d);

  printf("after...\n");
  display(arr, ARRAY_LEN);

  return 0;
}