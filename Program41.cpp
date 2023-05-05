#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE; 

class SinglyCLL
{
    public:
        PNODE First;
        PNODE Last;

        SinglyCLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
        int iCount();

};
/*
    Return_Value Class_Name :: Function_Name
    {

    }
*/

void SinglyCLL :: InsertFirst(int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(((*First) == NULL) && ((*Last) == NULL))  // Empty Linked List
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else  // Atleast one node
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}

void SinglyCLL :: InsertLast(int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(((*First) == NULL) && ((*Last) == NULL))  // Empty Linked List
    {
        *First = *Last = newn;
        (*Last)->next = *First;
    }
    else  // Atleast one node
    {
        (*Last)->next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}

void SinglyCLL :: Display()
{
    printf("Elements of linked list are :\n");

    do
    {
        printf("| %d |-> ",First->data);
        First = First->next;
    }while(First != Last->next);

    printf("\n");
}

int SinglyCLL :: Count()
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;
    }while(First != Last->next);

    return iCnt;
}

void SinglyCLL :: DeleteFirst()
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free(temp);
        (*Last)->next = *First;
    }
}

void SinglyCLL :: DeleteLast()
{
    PNODE temp = *First;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        while(temp->next != *Last)
        {
            temp = temp->next;
        }

        free(*Last);  // free(temp->next);
        *Last = temp;
        (*Last)->next = *First;
    }
}

void SinglyCLL :: InsertAtPosition(int no, int ipos)
{
    int inodecnt = 0, iCnt = 0;
    inodecnt = Count(*First,*Last);
    PNODE newn = NULL;
    PNODE temp = *First;

    if((ipos < 1) && (ipos > inodecnt+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,Last,no);
    }
    else if(ipos == inodecnt+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void SinglyCLL :: DeleteAtPosition(int ipos)
{
    int inodecnt = 0, iCnt = 0;
    inodecnt = Count(*First,*Last);
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    if((ipos < 1) && (ipos > inodecnt))
    {
        printf("Invalid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos == inodecnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        for(iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
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

    InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 121);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in Linked List are : %d\n",iRet);

    InsertAtPosition(&Head, &Tail, 103, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in Linked List are : %d\n",iRet);

    DeleteAtPosition(&Head, &Tail, 5);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in Linked List are : %d\n",iRet);

    DeleteFirst(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in Linked List are : %d\n",iRet);

    DeleteLast(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Number of nodes in Linked List are : %d\n",iRet);

    return 0;
}