#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));  // 1

    newn->data = No;
    newn->next = NULL;

    if(*First == NULL)  // If linked list is empty
    {
        *First = newn;
    }
    else  // If linked list contains atleast one node
    {
        newn->next = *First;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int main()
{
    // struct node * Head = NULL;
    PNODE Head = NULL;

    InsertFirst(&Head, 51);  // InsertFirst(60, 51);
    InsertFirst(&Head, 21);  // InsertFirst(60, 21);
    InsertFirst(&Head, 11);  // InsertFirst(60, 11);

    Display(Head);

    return 0;
}

/*
    Call by address :

    InsertFirst()
    InsertLast()
    InserAtPosition()

    DeleteFirst()
    DeleteLast()
    DeleteAtPosition()

    Call by value :

    Display()
    Count()
*/