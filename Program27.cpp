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

class SinglyLL
{
    public:
        PNODE First;  // Characteristics :
        int iCount;

        SinglyLL();  // Behaviours :

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeletePosition(int ipos);

        void Display();
};

/*
Return_Value Class_Name :: Function_Name(Parameters)
{

}
*/

SinglyLL :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

void SinglyLL :: InsertFirst(int no)
{
    // Step 1 : Allocate memory for node
    PNODE newn = new NODE;

    // Step 2 : Initialize the node
    newn->data = no;
    newn->next = NULL;

    // Step 3 : Check if LL is empty or not
    if(First == NULL)  // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else  // If LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

void SinglyLL :: InsertLast(int no)
{
    // Step 1 : Allocate memory for node
    PNODE newn = new NODE;
    PNODE temp = NULL;

    // Step 2 : Initialize the node
    newn->data = no;
    newn->next = NULL;

    // Step 3 : Check if LL is empty or not
    if(First == NULL)  // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else  // If LL contains atleast one node
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        iCount++;
    }
}

void SinglyLL :: InsertPosition(int no, int ipos)
{}

void SinglyLL :: DeleteFirst()
{}

void SinglyLL :: DeleteLast()
{}

void SinglyLL :: DeletePosition(int ipos)
{}

void SinglyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<" NULL\n";
}

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    cout<<"Number of nodes in first linked list are : "<<obj1.iCount<<"\n\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);

    obj1.Display();
    cout<<"Number of nodes in first linked list are : "<<obj1.iCount<<"\n\n";
    
    return 0;
}