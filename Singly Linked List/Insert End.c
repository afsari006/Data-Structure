#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAtEnd(struct node *head,int data)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;

    while(p->next!=NULL)
    {
        p=p->next;
    }

    p->next=ptr;
    ptr->next = NULL;

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = NULL;

    printf("Before insertion:\n");
    LinkedListTraversal(head);

    head = insertAtEnd(head, 56);

    printf("\nAfter insertion:\n");
    LinkedListTraversal(head);

    return 0;
}

