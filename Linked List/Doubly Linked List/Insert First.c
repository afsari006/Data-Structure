#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void traversal(struct node *head)
{
    struct node *ptr = head;

    while(ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node* insertFirst(struct node *head, int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if(head != NULL)
        head->prev = ptr;

    head = ptr;

    return head;
}

int main()
{
    struct node *head = NULL;

    head = insertFirst(head,30);
    head = insertFirst(head,20);
    head = insertFirst(head,10);

    printf("Original List:\n");
    traversal(head);

    head = insertFirst(head,5);
    printf("After Insert First:\n");
    traversal(head);

    return 0;
}
