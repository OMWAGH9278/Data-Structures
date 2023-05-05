#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
    public:
        PNODE First;
        SinglyLL();

        void InsertFirst(int no);
        void Display();
        int Count();
};

SinglyLL :: SinglyLL()
{
    First = NULL;
}

void SinglyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

void SinglyLL :: Display()
{
    PNODE temp = First;

    cout<<"Elements of Linked List are: "<<"\n";

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

int SinglyLL :: Count()
{
    PNODE temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        temp = temp->next;
        iCnt++;
    }
    return iCnt;
}

int main(void)
{
    SinglyLL obj;

    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    int iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return (0);
}