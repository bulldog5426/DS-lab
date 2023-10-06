#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* top = NULL;


void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}


void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp = top;

    top = top->next;

    free(temp);
}

void peek() {

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}


int main() {
    push(1);
    push(2);
    push(3);
    peek();
    pop();
    peek();
    pop();
    peek();
    pop();
    peek();
    return 0;
}
