#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void push(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int pop(Queue* q) {
    if (isEmpty(q)) {
        return -1; // Return -1 to indicate queue is empty
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int main() {
    Queue q;
    initQueue(&q);
    int rs[10000] = {0};
    int k = 0;

    while (1) {
        char cmd[10];
        scanf("%s", cmd);
        if (strcmp(cmd, "PUSH") == 0) {
            int curr;
            scanf("%d", &curr);
            push(&q, curr);
        } else if (strcmp(cmd, "POP") == 0) {
            int curr = pop(&q);
            rs[k] = (curr == -1) ? 0 : curr; // Save 0 if queue was empty
            k++;
        } else if (strcmp(cmd, "#") == 0) {
            break;
        }
    }

    for (int i = 0; i < k; i++) {
        if (rs[i] != 0) {
            printf("%d\n", rs[i]);
        } else {
            printf("NULL\n");
        }
    }

    return 0;
}
