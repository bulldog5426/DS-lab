#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to insert a new node at the end of the linked list
struct Node* insert(struct Node* head, int data) {
    if (head == NULL) {
        return createNode(data);
    } else {
        head->next = insert(head->next, data);
        return head;
    }
}

// Recursive function to traverse the linked list
void traverse(struct Node* head) {
    if (head != NULL) {
        printf("%d ", head->data);
        traverse(head->next);
    }
}

// Driver code
int main() {
    struct Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    traverse(head);
    return 0;
}

