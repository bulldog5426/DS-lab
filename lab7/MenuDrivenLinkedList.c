#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element before another element
void insertBefore(struct Node** head, int key, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        return;
    }

    if ((*head)->data == key) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element %d not found in the list.\n", key);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert an element after another element
void insertAfter(struct Node* head, int key, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", key);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a given element from the list
void deleteElement(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to traverse and print the list
void traverse(struct Node* head) {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to sort the list (insertion sort)
void sort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Already sorted or empty list
    }

    struct Node* sorted = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* search = sorted;
            while (search->next != NULL && search->next->data < current->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    *head = sorted;
}

// Function to delete every alternate node in the list
void deleteAlternate(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete alternate nodes.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}

// Function to insert an element in a sorted list such that the order is maintained
void insertInSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert an element at the start of the list
void insertAtStart(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete an element at the end of the list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Function to free memory and exit
void exitProgram(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    exit(0);
}

int main() {
    struct Node* head = NULL;
    int choice, key, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete a given element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in a sorted list\n");
        printf("9. Insert an element at the start\n");
        printf("10. Delete an element at the end\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key element: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertBefore(&head, key, data);
                break;

            case 2:
                printf("Enter the key element: ");
                scanf("%d", &key);
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertAfter(head, key, data);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                deleteElement(&head, key);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                reverse(&head);
                printf("List reversed.\n");
                break;

            case 6:
                sort(&head);
                printf("List sorted.\n");
                break;

            case 7:
                deleteAlternate(head);
                printf("Alternate nodes deleted.\n");
                break;

            case 8:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertInSorted(&head, data);
                break;

            case 9:
                printf("Enter the data to insert at the start: ");
                scanf("%d", &data);
                insertAtStart(&head, data);
                break;

            case 10:
                deleteAtEnd(&head);
                printf("Element at the end deleted.\n");
                break;

            case 11:
                exitProgram(head);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
