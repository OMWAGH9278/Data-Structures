#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCL
{
    public:
        PNODE First;
        PNODE Last;

        DoublyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

/*
        Return_Type Class_Name :: Function_Name
        {}
*/
DoublyCL :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

void DoublyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else  // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

void DoublyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else  // If LL contains one or more nodes
    {
        (Last)->next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

void DoublyCL :: Display()
{
    PNODE temp = First;

    if((First == NULL) && (Last ==NULL))
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked List are :"<<"\n";
    do
    {
        cout<<"| "<<temp->data<<" |<=> ";
        temp = temp->next;
    }while(temp != Last->next);
    cout<<"\n";
}

int DoublyCL :: Count()
{
    int iCnt = 0;
    PNODE temp = First;

    if((First == NULL) && (Last ==NULL))
    {
        return iCnt;;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);

    return iCnt;
}

void DoublyCL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last) // Single Node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else  // More than one node 
    {
        First = (First)->next;
        delete (Last)->next;  // delete (First)->prev;
        (First)->prev = Last;
        (Last)->next = First;
    }
}

void DoublyCL :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last) // Single Node
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else  // More than one node 
    {
        Last = (Last)->prev;
        delete (First)->prev;

        (First)->prev = Last;
        (Last)->next = First;
    }
}

void DoublyCL :: InsertAtPos(int no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

void DoublyCL :: DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    PNODE temp = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

int main()
{
    DoublyCL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertAtPos(105,5);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPos(5);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}