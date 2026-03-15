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

struct node* insertLast(struct node *head, int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL)
    {
        ptr->prev = NULL;
        return ptr;
    }

    struct node *p = head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

int main()
{
    struct node *head = NULL;

    head = insertLast(head,10);
    head = insertLast(head,20);
    head = insertLast(head,30);

    printf("Original List:\n");
    traversal(head);

    head = insertLast(head,40);
    printf("After Insert Last:\n");
    traversal(head);

    return 0;
}
