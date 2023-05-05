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
    // Step 1: Allocate the memory for new node
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    // Step 2: Initialise the node
    newn->data = No;
    newn->next = NULL;

    // Step 3: Check Linked list is empty or not
    if(*First == NULL)
    {
        *First = newn;
    }
    else  // If linked list contains atleast one node
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int No)
{
    PNODE temp = *First;

    // Step 1: Allocate the memory for new node
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    // Step 2: Initialise the node
    newn->data = No;
    newn->next = NULL;

    // Step 3: Check Linked list is empty or not
    if(*First == NULL)
    {
        *First = newn;
    }
    else  // If linked list contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements of linked list are:\n");
    while(First != NULL)
    {
        printf("| %d | -> ",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt = 0;
    while(First != NULL)
    {
        iCnt++;;
        First = First->next;
    }
    return iCnt;
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    InsertLast(&Head, 101);
    InsertLast(&Head, 111);

    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    return 0;
}

