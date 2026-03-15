
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* ptr = head;
    printf("List: ");
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to search for a value
struct Node* search(struct Node* head, int key) {
    struct Node* ptr = head;
    while(ptr != NULL) {
        if(ptr->data == key) {
            return ptr; // Node found
        }
        ptr = ptr->next;
    }
    return NULL; // Node not found
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Initialize nodes
    head->data = 10; head->prev = NULL; head->next = second;
    second->data = 20; second->prev = head; second->next = third;
    third->data = 30; third->prev = second; third->next = NULL;

    // Display the list
    traverseForward(head);

    // Search for a value
    int key = 20;
    struct Node* result = search(head, key);
    if(result != NULL)
        printf("Value %d found in the list.\n", key);
    else
        printf("Value %d not found in the list.\n", key);

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}

