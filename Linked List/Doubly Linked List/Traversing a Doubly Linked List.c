#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void traverseForward(struct Node* head) {
    struct Node* ptr = head;
    printf("Forward Traversal: ");
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void traverseBackward(struct Node* head) {
    struct Node* ptr = head;

    if(ptr == NULL) return;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    printf("Backward Traversal: ");
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));


    head->data = 10;
    head->prev = NULL;
    head->next = second;
    second->data = 20;
    second->prev = head;
    second->next = third;
    third->data = 30;
    third->prev = second;
    third->next = NULL;

    traverseForward(head);
    traverseBackward(head);

    free(head);
    free(second);
    free(third);

    return 0;
}
