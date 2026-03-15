#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void searchSorted(struct node *head, int item)
{
    struct node *ptr = head;
    int pos = 1;

    while(ptr != NULL && ptr->data <= item)
    {
        if(ptr->data == item)
        {
            printf("Item found at position %d\n", pos);
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    printf("Item not found\n");
}

int main()
{
    struct node *head, *n1, *n2;

    head = malloc(sizeof(struct node));
    n1 = malloc(sizeof(struct node));
    n2 = malloc(sizeof(struct node));

    head->data = 10;
    head->next = n1;

    n1->data = 20;
    n1->next = n2;

    n2->data = 30;
    n2->next = NULL;

    searchSorted(head, 20);

    return 0;
}
