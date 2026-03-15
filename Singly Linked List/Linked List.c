#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *start;
    struct node *N1;
    struct node *N2;
    struct node *N3;

    start = malloc(sizeof(struct node));
    N1 = malloc(sizeof(struct node));
    N2 = malloc(sizeof(struct node));
    N3 = malloc(sizeof(struct node));

    start->data = 10;
    start->next = N1;

    N1->data = 20;
    N1->next = N2;

    N2->data = 30;
    N2->next = N3;

    N3->data = 40;
    N3->next = NULL;

    struct node *ptr;
    ptr = start;

    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
