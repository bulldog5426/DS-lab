#include <stdio.h>
#include <stdlib.h>

// Definition for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print a doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to find the union of two doubly linked lists
struct Node* unionOfLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current = list1;

    while (current != NULL) {
        insertEnd(&result, current->data);
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        if (!search(result, current->data)) {
            insertEnd(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Function to find the intersection of two doubly linked lists
struct Node* intersectionOfLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* current = list1;

    while (current != NULL) {
        if (search(list2, current->data)) {
            insertEnd(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Function to search for a value in a doubly linked list
int search(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // Value found
        }
        current = current->next;
    }
    return 0; // Value not found
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n, m, value;

    printf("Enter the number of elements in list1: ");
    scanf("%d", &n);
    printf("Enter the elements for list1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    printf("Enter the number of elements in list2: ");
    scanf("%d", &m);
    printf("Enter the elements for list2: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* unionList = unionOfLists(list1, list2);
    struct Node* intersectionList = intersectionOfLists(list1, list2);

    printf("Union of Lists: ");
    printList(unionList);

    printf("Intersection of Lists: ");
    printList(intersectionList);

    return 0;
}
