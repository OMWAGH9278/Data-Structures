#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCircularLL
{
    public:
        PNODE First;
        PNODE Last;
        int iCount;

        DoublyCircularLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

class Logic : public DoublyCircularLL
{
    public:
        void DisplayReverse();
};

DoublyCircularLL :: DoublyCircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void DoublyCircularLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        First->prev = Last;
        Last->next = First;
        iCount++;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
        First->prev = Last;
        Last->next = First;
        iCount++;
    }
}

void DoublyCircularLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        First->prev = Last;
        Last->next = First;
        iCount++;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
        First->prev = Last;
        Last->next = First;
        iCount++;
    }
}

void DoublyCircularLL :: InsertAtPosition(int no, int ipos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

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
        newn = new NODE;
        temp = First;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next = temp->next->prev = newn;
        iCount++;
    }
}

void DoublyCircularLL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First == NULL;
        Last == NULL;
        iCount--;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
        iCount--;
    }
}

void DoublyCircularLL :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete Last;
        First == NULL;
        Last == NULL;
        iCount--;
    }
    else
    {
        Last = Last->prev;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
        iCount--;
    }
}

void DoublyCircularLL :: DeleteAtPosition(int ipos)
{
    PNODE temp = NULL;

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
        temp = First;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

void DoublyCircularLL :: Display()
{
    PNODE temp = First;

    cout<<"Elements of linked list are->"<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }while(temp != First);
    cout<<"\n";
}

void Logic :: DisplayReverse()
{
    PNODE temp = Last;

    cout<<"Elements of linked list in reverse are->"<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->prev;
    }while(temp != Last);
    cout<<"\n";
}

int main()
{
    Logic lobj;

    lobj.InsertFirst(51);
    lobj.InsertFirst(21);
    lobj.InsertFirst(11);
    lobj.Display();
    lobj.DisplayReverse();
    cout<<"Number of elements in linked list are : "<<lobj.iCount<<"\n";

    lobj.InsertLast(101);
    lobj.InsertLast(121);
    lobj.InsertLast(151);
    lobj.Display();
    lobj.DisplayReverse();
    cout<<"Number of elements in linked list are : "<<lobj.iCount<<"\n";

    lobj.InsertAtPosition(105, 5);
    lobj.Display();
    lobj.DisplayReverse();
    cout<<"Number of elements in linked list are : "<<lobj.iCount<<"\n";

    lobj.DeleteAtPosition(5);
    lobj.Display();
    lobj.DisplayReverse();
    cout<<"Number of elements in linked list are : "<<lobj.iCount<<"\n";

    lobj.DeleteFirst();
    lobj.Display();
    lobj.DisplayReverse();
    cout<<"Number of elements in linked list are : "<<lobj.iCount<<"\n";

    lobj.DeleteLast();
    lobj.Display();
    lobj.DisplayReverse();
    cout<<"Number of elements in linked list are : "<<lobj.iCount<<"\n";

    return 0;
}