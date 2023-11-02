#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int value;
    struct ListNode* next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeSortedLists(struct ListNode* x, struct ListNode* y) {
    if (!x) {
        return y;
    }
    if (!y) {
        return x;
    }

    struct ListNode* merged;

    if (x->value < y->value) {
        merged = x;
        x = x->next;
    } else {
        merged = y;
        y = y->next;
    }

    struct ListNode* current = merged;

    while (x && y) {
        if (x->value < y->value) {
            current->next = x;
            x = x->next;
        } else {
            current->next = y;
            y = y->next;
        }
        current = current->next;
    }

    if (x) {
        current->next = x;
    }
    if (y) {
        current->next = y;
    }

    return merged;
}

// Function to create a linked list from an array of values
struct ListNode* createLinkedList(int values[], int n) {
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;

    for (int i = 0; i < n; i++) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->value = values[i];
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Function to print a linked list
void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int x_values[100], y_values[100];
    int n, m;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements for the first linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x_values[i]);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &m);
    printf("Enter the elements for the second linked list: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &y_values[i]);
    }

    struct ListNode* x = createLinkedList(x_values, n);
    struct ListNode* y = createLinkedList(y_values, m);

    struct ListNode* z = mergeSortedLists(x, y);

    printf("Merged Linked List Z:\n");
    printLinkedList(z);

    return 0;
}
