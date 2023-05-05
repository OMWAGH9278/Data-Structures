
// Doubly Linear Linked List

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLLL
{
    public:
        PNODE First;
        int iCount;

        DoublyLLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

DoublyLLL :: DoublyLLL()
{
    First = NULL;
    iCount = 0;
}

void DoublyLLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        newn->next = First;
        First = newn;
        First->next->prev = First;
        iCount++;
    }
}

void DoublyLLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        iCount++;
    }
    else
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newn->prev = temp;
        temp->next = newn;
        iCount++;
    }
}

void DoublyLLL :: InsertAtPosition(int no,int ipos)
{
    if((ipos < 1) || (ipos > iCount+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else 
    {
        PNODE newn = new NODE; 
        PNODE temp = First;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
        iCount++;
    }
}

void DoublyLLL :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        First = First->next;
        delete (First->prev);
        iCount--;
    }
}

void DoublyLLL :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete (temp->next);
        temp->next = NULL;
        iCount--;
    }
}

void DoublyLLL :: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        PNODE temp = First;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
        iCount--;
    }
}

void DoublyLLL :: Display()
{
    cout<<"Elements of linked list are :"<<"\n";;

    PNODE temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"\n";
}

int main()
{
    DoublyLLL dobj1;
    int iRet = 0;

    dobj1.InsertFirst(51);
    dobj1.InsertFirst(21);
    dobj1.InsertFirst(11);
    dobj1.Display();
    iRet = dobj1.iCount;
    cout<<"Number of nodes in linked list are : "<<iRet<<"\n";

    dobj1.InsertLast(101);
    dobj1.InsertLast(111);
    dobj1.InsertLast(121);
    dobj1.Display();
    iRet = dobj1.iCount;
    cout<<"Number of nodes in linked list are : "<<iRet<<"\n";

    dobj1.InsertAtPosition(105, 5);
    dobj1.Display();
    iRet = dobj1.iCount;
    cout<<"Number of nodes in linked list are : "<<iRet<<"\n";

    dobj1.DeleteAtPosition(5);
    dobj1.Display();
    iRet = dobj1.iCount;
    cout<<"Number of nodes in linked list are : "<<iRet<<"\n";

    dobj1.DeleteFirst();
    dobj1.Display();
    iRet = dobj1.iCount;
    cout<<"Number of nodes in linked list are : "<<iRet<<"\n";

    dobj1.DeleteLast();
    dobj1.Display();
    iRet = dobj1.iCount;
    cout<<"Number of nodes in linked list are : "<<iRet<<"\n";

    return 0;
}