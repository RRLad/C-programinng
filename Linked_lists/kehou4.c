#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    // Handle empty list cases
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    // Create a dummy head node for easier list building
    struct Node dummy = {0, NULL};
    struct Node* tail = &dummy;
    
    // Compare and merge while both lists have nodes
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Attach remaining nodes from either list
    tail->next = (l1 != NULL) ? l1 : l2;
    
    return dummy.next;
}

// Function to create a linked list from input
struct Node* createList() {
    int num;
    struct Node dummy = {0, NULL};
    struct Node* tail = &dummy;
    
    // Read numbers until newline
    while (scanf("%d", &num) == 1) {
        tail->next = createNode(num);
        tail = tail->next;
        
        // Check for newline or space
        char c = getchar();
        if (c == '\n' || c == EOF) break;
    }
    
    return dummy.next;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create first linked list
    struct Node* list1 = createList();
    
    // Create second linked list
    struct Node* list2 = createList();
    
    // Merge the lists
    struct Node* mergedList = mergeLists(list1, list2);
    
    // Print the result
    printList(mergedList);
    
    return 0;
}