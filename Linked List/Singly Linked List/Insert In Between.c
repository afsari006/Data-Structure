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
struct node *insertInBetween(struct node *head,int data,int index)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next=ptr;

    return head;
};

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

    head = insertInBetween(head,56,1);

    printf("\nAfter insertion:\n");
    LinkedListTraversal(head);


    return 0;
}


