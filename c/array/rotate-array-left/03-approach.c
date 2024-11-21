// juggling algorithm
// time complexity O(n)
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

int gcd(int a, int b) {
  while (b != 0)
  {
    int temp = b;
    b = a % b;
    a = temp;
  }
  
  return a;
}

void rotatearr(int arr[], int n, int d) {
  d %= n;

  int cycles = gcd(n, d);
  for (size_t i = 0; i < cycles; i++)
  {
    int start = arr[i];
    int cur_idx = i, nxt_idx;

    while (1)
    {
      nxt_idx = (cur_idx + d) % n;

      if (nxt_idx == i) {
        break;
      }

      arr[cur_idx] = arr[nxt_idx];
      cur_idx = nxt_idx;
    }

    arr[cur_idx] = start;
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

  printf("Juggling algorithm\n");
  printf("left rotate array by %d positions\n", d);
  printf("before...\n");
  display(arr, ARRAY_LEN);

  rotatearr(arr, ARRAY_LEN, d);

  printf("after...\n");
  display(arr, ARRAY_LEN);

  return 0;
}