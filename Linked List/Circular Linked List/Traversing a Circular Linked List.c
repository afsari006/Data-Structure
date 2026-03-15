#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traverseCircularHeaderList(struct node *header) {
    if(header == NULL || header->next == header) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = header->next;

    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while(ptr != header);
    printf("HEADER\n");
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
    traverseCircularHeaderList(header);
    return 0;
}
