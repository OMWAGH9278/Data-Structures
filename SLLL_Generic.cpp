#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node* next;
};

template <class T>
class SinglyLL
{
    public:
        struct node<T>* First;
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int position);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int position);

        void Display();
        int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct node<T>* newn = new node<T>;

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

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct node<T>* newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
        First = newn;
    else
    {
        struct node<T>* temp = First;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertAtPosition(T no, int position)
{
    int nodeCnt = Count();
    struct node<T>* temp = First;
    int iCnt = 0;

    struct node<T>* newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if((position < 1) && (position > (nodeCnt+1)))
    {
        cout<<"Invalid position"<<"\n";
        exit (-1);
    }

    if(position == 1)
        InsertFirst(no);
    else if(position == nodeCnt+1)
        InsertLast(no);
    else
    {
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp = temp->next;
        
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)
        return;
    
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T>* temp = First;
        First = First->next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
        return;
    
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T>* temp = First;
        while(temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }   
}

template <class T>
void SinglyLL<T> :: DeleteAtPosition(int position)
{
    int nodeCnt = Count();
    struct node<T>* temp1 = First;
    struct node<T>* temp2 = NULL;
    int iCnt = 0;

    if((position < 1) && (position > nodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        exit (-1);
    }

    if(position == 1)
        DeleteFirst();
    else if(position == nodeCnt)
        DeleteLast();
    else
    {
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp1 = temp1->next;
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct node<T>* temp = First;

    cout<<"\nElements of Linked List are: "<<"\n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    struct node<T>* temp = First;
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
    SinglyLL<int> iobj;

    iobj.InsertFirst(101);
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.Display();
    int iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.InsertLast(151);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.InsertAtPosition(71, 4);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteAtPosition(4);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    iobj.DeleteLast();
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL<char> cobj;

    cobj.InsertFirst('F');
    cobj.InsertFirst('X');
    cobj.InsertFirst('J');
    cobj.InsertFirst('r');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.InsertLast('D');
    cobj.InsertLast('g');
    cobj.InsertLast('5');
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.InsertAtPosition('b', 4);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.DeleteAtPosition(4);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    cobj.DeleteLast();
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL<float> fobj;

    fobj.InsertFirst(101.54);
    fobj.InsertFirst(51.45);
    fobj.InsertFirst(21.13);
    fobj.InsertFirst(11.67);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.InsertLast(111.83);
    fobj.InsertLast(121.83);
    fobj.InsertLast(151.06);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.InsertAtPosition(71.16, 4);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.DeleteAtPosition(4);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.DeleteFirst();
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    fobj.DeleteLast();
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    SinglyLL<double> dobj;

    dobj.InsertFirst(101.273897);
    dobj.InsertFirst(51.097245);
    dobj.InsertFirst(21.272632);
    dobj.InsertFirst(11.826352);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertLast(111.259335);
    dobj.InsertLast(121.214589);
    dobj.InsertLast(151.236541);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.InsertAtPosition(71.125896, 4);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    dobj.DeleteAtPosition(4);
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

    return (0);
}