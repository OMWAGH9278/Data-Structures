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
    // PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE newn = new NODE;

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
    // PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE newn = new NODE;

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
    cout<<"Elements of linked list are :"<<"\n";

    do
    {
        cout<<"| "<<First->data>>" |->"<<"\n";
        First = First->next;
    }while(First != Last->next);

    cout<<"\n";
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
        delete *First;
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        delete temp;
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
        delete *First;
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        while(temp->next != *Last)
        {
            temp = temp->next;
        }

        delete *Last;  // delete (temp->next);
        *Last = temp;
        (*Last)->next = *First;
    }
}

void SinglyCLL :: InsertAtPosition(int no, int ipos)
{
    int inodecnt = 0, iCnt = 0;
    inodecnt = Count();
    PNODE newn = NULL;
    PNODE temp = *First;

    if((ipos < 1) && (ipos > inodecnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == inodecnt+1)
    {
        InsertLast(no);
    }
    else
    {
        // newn = (PNODE)malloc(sizeof(NODE));
        newn = new NODE;

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
    inodecnt = Count();
    PNODE temp1 = *First;
    PNODE temp2 = NULL;

    if((ipos < 1) && (ipos > inodecnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == inodecnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        // free (temp2);
        delete temp2;
    }
}

int main()
{
    SinglyCLL obj;

    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in Linked List are : "<<iRet<<"\n";

    obj.InsertAtPosition(103, 5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in Linked List are : "<<iRet<<"\n";

    obj.DeleteAtPosition(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in Linked List are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in Linked List are : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes in Linked List are : "<<iRet<<"\n";

    return 0;
}