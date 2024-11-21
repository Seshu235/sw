#include <stdio.h>
#include <stdlib.h>

struct queue {
  int value;
  struct queue *next;
};

struct queue *createNode(int data) {
  struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
  if (newNode == NULL) {
    return NULL;
  }

  newNode->value = data;
  newNode->next = NULL;

  return newNode;
}

void enqueue(struct queue **head, int val) {
  struct queue *newNode = createNode(val);

  if (newNode == NULL) {
    perror("memory not allocated");
  }

  if (*head == NULL) {
    *head = newNode;
    return;
  } 
  
  struct queue *tmp = *head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }

  tmp->next = newNode;
}

void dequeue(struct queue **head) {
  struct queue *tmp = *head;
  tmp = tmp->next;
}

void list(struct queue *head) {
  struct queue *tmp = head;

  while (tmp != NULL) {
    printf("%d ", tmp->value);
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {
  struct queue *head = NULL;

  enqueue(&head, 1);
  enqueue(&head, 2);
  enqueue(&head, 3);
  enqueue(&head, 4);
  enqueue(&head, 5);

  dequeue(&head);

  list(head);
}
