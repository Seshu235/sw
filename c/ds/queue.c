#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
typedef struct Node {
  int data;
  struct Node *next;
}node;

// Define the structure for the queue
typedef struct Queue {
  node *front;
  node *rear;
}queue;

node *createNode(int data) {
  // Allocate memory for a new node
  node *newnode = (node *)malloc(sizeof(node));
  if (newnode == NULL) {
    return NULL;
  }

  newnode->data = data;
  newnode->next = NULL;

  return newnode;
}

queue *createQueue() {
  queue *newqueue = (queue *)malloc(sizeof(queue));
  if (newqueue == NULL) {
    return NULL;
  }

  newqueue->front = newqueue->rear = NULL;

  return newqueue;
}

int isEmpty(queue *q) {
  return q->front == NULL;
}

void enqueue(queue *q, int data) {
  node *newnode = createNode(data);
  if (!newnode) {
    printf("Queue Overflow!\n");
    return;
  }

  if (q->rear == NULL) {
    q->front = q->rear = newnode;
    return;
  }

  q->rear->next = newnode;
  q->rear = newnode;
}

int dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue Underflow\n");
    return -1;
  }

  node *temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  int data = temp->data;
  free(temp);

  return data;
}

int peek(queue *q) {
  if (isEmpty(q)) {
    return -1;
  }

  return q->front->data;
}

void printqueue(queue *q) {
  node *temp = q->front;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() 
{
  queue *q = createQueue();

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);

  printf("Queue: ");
  printqueue(q);

  dequeue(q);
  dequeue(q);

  printf("Queue: ");
  printqueue(q);

  return 0;
}