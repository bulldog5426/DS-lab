#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 3  // Maximum number of stacks
#define STACK_SIZE 10 // Size of each stack

int arr[MAX_STACKS * STACK_SIZE]; // The array to hold multiple stacks
int top[MAX_STACKS];              // Array to track the top of each stack

// Initialize all stack tops to -1 (empty)
void initialize() {
    for (int i = 0; i < MAX_STACKS; i++) {
        top[i] = -1;
    }
}

// Check if a stack is empty
int isEmpty(int stackNumber) {
    return top[stackNumber] == -1;
}

// Check if a stack is full
int isFull(int stackNumber) {
    return top[stackNumber] == (stackNumber + 1) * STACK_SIZE - 1;
}

// Push an element onto a specific stack
void push(int stackNumber, int value) {
    if (isFull(stackNumber)) {
        printf("Stack %d is full. Cannot push.\n", stackNumber);
        return;
    }
    top[stackNumber]++;
    arr[top[stackNumber]] = value;
}

// Pop an element from a specific stack
int pop(int stackNumber) {
    if (isEmpty(stackNumber)) {
        printf("Stack %d is empty. Cannot pop.\n", stackNumber);
        return -1;
    }
    int value = arr[top[stackNumber]];
    top[stackNumber]--;
    return value;
}

// Display the elements of a specific stack
void display(int stackNumber) {
    if (isEmpty(stackNumber)) {
        printf("Stack %d is empty.\n", stackNumber);
        return;
    }
    printf("Stack %d elements: ", stackNumber);
    for (int i = stackNumber * STACK_SIZE; i <= top[stackNumber]; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    initialize();

    push(0, 1);
    push(0, 2);
    push(0, 3);

    push(1, 4);
    push(1, 5);

    push(2, 6);

    display(0);
    display(1);
    display(2);

    printf("Popped from stack 0: %d\n", pop(0));
    printf("Popped from stack 1: %d\n", pop(1));

    display(0);
    display(1);
    display(2);

    return 0;
}
