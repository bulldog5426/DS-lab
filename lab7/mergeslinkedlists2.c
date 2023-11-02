#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int value;
    struct ListNode* next;
};

// Function to merge two linked lists as specified
struct ListNode* mergeLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list3 = NULL;
    struct ListNode* current = NULL;

    while (list1 || list2) {
        if (list1) {
            if (!list3) {
                list3 = list1;
                current = list3;
            } else {
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        }

        if (list2) {
            if (!list3) {
                list3 = list2;
                current = list3;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        }
    }

    return list3;
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
    int n, m;
    printf("Enter the number of elements in list1: ");
    scanf("%d", &n);

    int* list1_values = (int*)malloc(n * sizeof(int));
    printf("Enter the elements for list1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list1_values[i]);
    }

    printf("Enter the number of elements in list2: ");
    scanf("%d", &m);

    int* list2_values = (int*)malloc(m * sizeof(int));
    printf("Enter the elements for list2: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &list2_values[i]);
    }

    struct ListNode* list1 = createLinkedList(list1_values, n);
    struct ListNode* list2 = createLinkedList(list2_values, m);

    struct ListNode* list3 = mergeLists(list1, list2);

    printf("Merged Linked List list3:\n");
    printLinkedList(list3);

    free(list1_values);
    free(list2_values);
    return 0;
}
