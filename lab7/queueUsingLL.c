#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* front = NULL;
struct Node* rear = NULL;


void enqueue(int val) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}


void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    // Create a temporary pointer to the current front of the queue
    struct Node* temp = front;
    // Update the front pointer to point to the next node in the queue
    front = front->next;
    // If front is NULL, set rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }
    // Free the memory allocated to the temporary pointer
    free(temp);
}


void peek() {

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

// Main function to test the queue
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    peek();
    dequeue();
    peek();
    dequeue();
    peek();
    dequeue();
    peek();
    return 0;
}
