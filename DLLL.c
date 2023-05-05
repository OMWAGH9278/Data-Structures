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

        newn->prev = temp;  // X
        temp->next = newn;

    }
}

void Display(PNODE First)
{
    printf("Elements of linked list are :\n");
    printf("NULL<=>");

    while(First != NULL)
    {
        printf("| %d |<=> ",First->data);
        First = First->next;
    }

    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }

    return iCnt;
}

void DeleteFirst(PPNODE First)
{

    if(*First == NULL)  // Empty Linked List
    {
        return;
    }
    else if((*First)->next == NULL)  // One Element in LL
    {
        free(*First);
        *First = NULL;
    }
    else
    {
       *First = (*First)->next;
       free((*First)->prev);  // X
       (*First)->prev = NULL;  // X 
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }   

        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First, int No, int iPos)
{
    int nodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    nodeCnt = Count(*First);

    if((iPos < 1) || (iPos > (nodeCnt + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, No);
    }
    else if(iPos == (nodeCnt + 1))
    {
        InsertLast(First, No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        temp = *First;
        for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteAtPos(PPNODE First,  int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0, nodeCnt = 0;
    nodeCnt = Count(*First);

    if((iPos < 1) || (iPos > nodeCnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == nodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;

        for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  // temp1->next = temp1->next->next;
        temp2->prev = temp1;  // X 
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    Display(Head);

    InsertFirst(&Head, 21);
    Display(Head);

    InsertFirst(&Head, 11);
    Display(Head);

    InsertLast(&Head, 101);
    Display(Head);

    InsertLast(&Head, 111);
    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet); 

    InsertLast(&Head, 121);

    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    InsertAtPos(&Head, 105, 5);
    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    DeleteAtPos(&Head, 5);
    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    DeleteFirst(&Head);
    DeleteLast(&Head);

    Display(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    return 0;
}