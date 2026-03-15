#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node* searchCircularHeaderList(struct node *header, int key) {
    if(header == NULL || header->next == header)
    {
        return NULL;
    }

    struct node *ptr = header->next;

    do {
        if(ptr->data == key) {
            return ptr;
        }
        ptr = ptr->next;
    } while(ptr != header);

    return NULL;
}

struct node* createCircularHeaderList(int n) {
    struct node *header = (struct node*)malloc(sizeof(struct node));
    header->next = header;
    struct node *last = header;

    for(int i = 1; i <= n; i++) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = i;
        newNode->next = header;
        last->next = newNode;
        last = newNode;
    }

    return header;
}

int main() {
    struct node *header = createCircularHeaderList(5);

    int key = 3;
    struct node *result = searchCircularHeaderList(header, key);

    if(result != NULL) {
        printf("Element %d found.\n", key);
    } else {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
