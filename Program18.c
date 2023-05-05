#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;  // X
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;  // X

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;  // X
        *First = newn;
    }
}

void InsertLast(PPNODE First, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *First;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;  // X

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next; 
        }

        newn->prev = temp  // X
        (*First)->next = newn;

    }
}

void Display(PNODE First)
{
    printf("Elements of linked list are :\n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First->next;
    }

    printf("NULL\n");
}

int

int main()
{
    PNODE Head = NULL;

    return 0;
}