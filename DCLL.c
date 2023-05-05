#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
    }
    else
    {
        (*First)->prev = newn;
        newn->next = *First;
        *First = newn;
    }

    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
    }
    
    (*First)->prev = *Last;
    (*Last)->next = *First;
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev);
        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = *Last = NULL;
    }
    else
    {
        *Last = (*Last)->prev;
        free((*Last)->next);
        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void Display(PNODE First, PNODE Last)
{
    printf("\nElements of linked list are :\n");
    do
    {
        printf("| %d |<=>",First->data);
        First = First->next;
    }while(First != Last->next);
    printf("\n");
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;
    }while(First != Last->next);
    return iCnt;
}

void InsertAtPosition(PPNODE First, PPNODE Last, int no, int ipos)
{
    int nodecnt = 0, iCnt = 0;
    nodecnt = Count(*First, *Last);
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((ipos < 1) || (ipos > nodecnt+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,Last,no);
    }
    else if(ipos == nodecnt+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        PNODE temp = *First;   

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL; 

        for(iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = temp->next = newn;
    }
}

void DeleteAtPosition(PPNODE First, PPNODE Last, int ipos)
{
    int nodecnt = 0, iCnt = 0;
    nodecnt = Count(*First, *Last);
    PNODE temp = NULL;

    if((ipos < 1) || (ipos > nodecnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos == nodecnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        PNODE temp = *First;   

        for(iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;

    InsertFirst(&Head, &Tail, 51);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 11);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in linked list are : %d\n",iRet);

    InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 121);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in linked list are : %d\n",iRet);

    InsertAtPosition(&Head, &Tail, 105, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in linked list are : %d\n",iRet);

    DeleteAtPosition(&Head, &Tail, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in linked list are : %d\n",iRet);

    DeleteFirst(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in linked list are : %d\n",iRet);

    DeleteLast(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in linked list are : %d\n",iRet);

    return 0;
}