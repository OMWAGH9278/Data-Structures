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

class SinglyCircularLL
{
    public:
        PNODE First;
        PNODE Last;
        int iCount;

        SinglyCircularLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);

        void Display();
};

SinglyCircularLL :: SinglyCircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

void SinglyCircularLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        Last->next = First;
        iCount++;
    } 
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
        iCount++;
    }
}

void SinglyCircularLL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        Last->next = First;
        iCount++;
    } 
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
        iCount++;
    }
}

void SinglyCircularLL :: Display()
{
    PNODE temp = First;
    cout<<"Elements of Singly Circular Linked List are :"<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != First);

    cout<<"\n";
}

void SinglyCircularLL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
        iCount--;
    }
    else
    {
        First = First->next;
        delete Last->next;  // delete temp;
        Last->next = First;
        iCount--;
    }
}

void SinglyCircularLL :: DeleteLast()
{
    PNODE temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
        iCount--;
    }
    else
    {
        while(temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First;
        iCount--;
    }
}

void SinglyCircularLL :: InsertAtPosition(int no, int ipos)
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

        for(int iCnt = 1;iCnt < (ipos-1);iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

void SinglyCircularLL :: DeleteAtPosition(int ipos)
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
        PNODE temp1 = First;
        PNODE temp2 = NULL;

        for(int iCnt = 1;iCnt < (ipos-1);iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

int main()
{
    SinglyCircularLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.Display();
    cout<<"Number of nodes in Linked List are : "<<obj1.iCount<<"\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);
    obj1.Display();
    cout<<"Number of nodes in Linked List are : "<<obj1.iCount<<"\n";

    obj1.InsertAtPosition(107, 5);
    obj1.Display();
    cout<<"Number of nodes in Linked List are : "<<obj1.iCount<<"\n";

    obj1.DeleteAtPosition(5);
    obj1.Display();
    cout<<"Number of nodes in Linked List are : "<<obj1.iCount<<"\n";

    obj1.DeleteFirst();
    obj1.Display();
    cout<<"Number of nodes in Linked List are : "<<obj1.iCount<<"\n";

    obj1.DeleteLast();
    obj1.Display();
    cout<<"Number of nodes in Linked List are : "<<obj1.iCount<<"\n";

    return 0;
}