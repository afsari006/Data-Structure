#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node* deletePos(struct node *head, int pos)
{
    struct node *p = head;
    struct node *q = head->next;

    int i = 1;

    while(i < pos-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
}

int main()
{
    struct node *head;
    struct node *n1;
    struct node *n2;
    struct node *n3;
    struct node *n4;

    head = malloc(sizeof(struct node));
    n1 = malloc(sizeof(struct node));
    n2 = malloc(sizeof(struct node));
    n3 = malloc(sizeof(struct node));
    n4 = malloc(sizeof(struct node));

    head->data = 10;
    head->next = n1;

    n1->data = 20;
    n1->next = n2;

    n2->data = 30;
    n2->next = n3;

    n3->data = 40;
    n3->next = n4;

    n4->data = 50;
    n4->next = NULL;

    printf("Original Linked List:\n");
    traversal(head);

    head = deletePos(head,2);
    printf("After Deleting Position:\n");
    traversal(head);

    return 0;
}

