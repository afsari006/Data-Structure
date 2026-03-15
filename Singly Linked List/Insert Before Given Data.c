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
    printf("NULL\n");
}

struct node* insertBeforeData(struct node *head, int target, int newData)
{
    struct node *ptr = head;
    struct node *newnode;

    if(head != NULL && head->data == target)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = newData;
        newnode->next = head;
        return newnode;
    }

    while(ptr->next != NULL && ptr->next->data != target)
    {
        ptr = ptr->next;
    }

    if(ptr->next != NULL)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = newData;
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

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

    head = insertBeforeData(head, 11, 56);

    printf("After insertion:\n");
    LinkedListTraversal(head);

    return 0;
}

