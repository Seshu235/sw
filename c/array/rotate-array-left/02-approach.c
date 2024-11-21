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

  int temp[n] = {0};

  // copy last n-d elements to the front of the temp
  for (size_t i = 0; i < n-d; i++)
  {
    temp[i] = arr[d+i];
  }

  // copy the first d elements to the last of the temp
  for (size_t i = 0; i < d; i++)
  {
    temp[n-d+i] = arr[i];
  }
  

  for (size_t i = 0; i < n; i++)
  {
    arr[i] = temp[i];
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

  printf("Naive Approach using temp array\n");
  printf("left rotate array by %d positions\n", d);
  printf("before...\n");
  display(arr, ARRAY_LEN);

  rotatearr(arr, ARRAY_LEN, d);

  printf("after...\n");
  display(arr, ARRAY_LEN);

  return 0;
}