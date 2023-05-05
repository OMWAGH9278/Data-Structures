#include <iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
};

template<class T>
class SCLL
{
    public:
        struct node<T>* First;
        struct node<T>* Last;

        SCLL();

        void insert_first(T data);
        void insert_last(T data);
        void insert_position(int position, T data);

        void delete_first();
        void delete_last();
        void delete_position(int position);

        void display();
        int count();
};

int main(void)
{
    SCLL<int> sobj;
    int element_count = 0;
    
    sobj.insert_first(51);
    sobj.insert_first(21);
    sobj.insert_first(11);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List are : "<<element_count<<"\n";

    sobj.insert_last(101);
    sobj.insert_last(111);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List are : "<<element_count<<"\n";

    sobj.insert_position(5, 105);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List are : "<<element_count<<"\n";

    sobj.delete_position(5);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List are : "<<element_count<<"\n";

    sobj.delete_first();
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List are : "<<element_count<<"\n";

    sobj.delete_last();
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List are : "<<element_count<<"\n";
    
    return (0);
}

template<class T>
SCLL<T> :: SCLL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SCLL<T> :: insert_first(T data)
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    (Last)->next = First;
}

template<class T>
void SCLL<T> :: insert_last(T data)
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        (Last)->next = newn;
        Last = newn;
    }
    (Last)->next = First;
}

template<class T>
void SCLL<T> :: insert_position(int position, T data)
{
    int nodeCnt = count();
    int iCnt = 0;
    struct node<T>* temp = NULL;

    struct node<T>* newn = NULL;

    if((position < 1) && (position > nodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        exit(-1);
    }

    if(position == 1)
    {
        insert_first(data);
    }
    else if(position == nodeCnt+1)
    {
        insert_last(data);
    }
    else
    {
        newn = new node<T>;

        newn->data = data;
        newn->next = NULL;

        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SCLL<T> :: delete_first()
{
    struct node<T>* temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(((First)->next == NULL))
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        First = (First)->next;
        free(temp);
        (Last)->next = First;
    }
}

template<class T>
void SCLL<T> :: delete_last()
{
    struct node<T>* temp = NULL;
    int iCnt = 0;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(((First)->next == NULL))
    {
        free(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp->next != Last)
        {
            temp = temp->next;
        }

        Last = temp;
        free(temp->next);
        (Last)->next = First;
    }
}

template<class T>
void SCLL<T> :: delete_position(int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    struct node<T>* temp1 = NULL;
    struct node<T>* temp2 = NULL;

    if((position < 1) && (position > nodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        exit(-1);
    }

    if(position == 1)
    {
        delete_first();
    }
    else if(position == nodeCnt)
    {
        delete_last();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}

template<class T>
void SCLL<T> :: display()
{
    struct node<T>* temp = First;

    cout<<"Elements of Linked List are:"<<"\n";
    do
    {
        printf("| %d | -> ", temp->data);
        temp = temp->next;
    }
    while(temp != Last->next);
    cout<<"NULL\n"<<"\n";
}

template<class T>
int SCLL<T> :: count()
{
    struct node<T>* temp = First;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != Last->next);
    return (count);
}
