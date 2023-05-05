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
{}
void SinglyLL :: InsertLast(int no)
{}
void SinglyLL :: InsertPosition(int no, int ipos)
{}

void SinglyLL :: DeleteFirst()
{}
void SinglyLL :: DeleteLast()
{}
void SinglyLL :: DeletePosition(int ipos)
{}

void SinglyLL :: Display()
{}

int main()
{
    SinglyLL obj1;

    cout<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains : "<<obj1.First<<"\n";
    cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

    return 0;
}