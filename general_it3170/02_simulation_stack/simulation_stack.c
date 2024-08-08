#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

void initStack(Stack* s, int capacity) {
    s->data = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top < s->capacity - 1) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; // or some error code
}

int top(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1; // or some error code
}

void freeStack(Stack* s) {
    free(s->data);
}

int main() {
    Stack s;
    initStack(&s, 10000);
    int rs[10000];
    int k = 0;

    while (1) {
        char cmd[5];
        scanf("%s", cmd);
        if (strcmp(cmd, "PUSH") == 0) {
            int curr;
            scanf("%d", &curr);
            push(&s, curr);
        } else if (strcmp(cmd, "POP") == 0) {
            if (!isEmpty(&s)) {
                int curr = top(&s);
                rs[k] = curr;
                pop(&s);
            }
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

    freeStack(&s);
    return 0;
}
