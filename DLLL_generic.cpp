#include <iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node* next;
    struct node* prev;
};

template<class T>
class SCLL
{
    public:
        struct node<T>* First;

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
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    sobj.insert_last(101);
    sobj.insert_last(111);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    sobj.insert_position(5,105);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    sobj.delete_position(5);
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    sobj.delete_first();
    sobj.delete_last();
    sobj.display();
    element_count = sobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    SCLL<char> cobj;
    element_count = 0;
    
    cobj.insert_first('a');
    cobj.insert_first('N');
    cobj.insert_first('T');
    cobj.display();
    element_count = cobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    cobj.insert_last('j');
    cobj.insert_last('v');
    cobj.display();
    element_count = cobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    cobj.insert_position(5,'S');
    cobj.display();
    element_count = cobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    cobj.delete_position(5);
    cobj.display();
    element_count = cobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    cobj.delete_first();
    cobj.delete_last();
    cobj.display();
    element_count = cobj.count();
    cout<<"Number of elements in Linked List : "<<element_count<<"\n";

    return (0);
}

template<class T>
SCLL<T> :: SCLL()
{
    First = NULL;
}

template<class T>
void SCLL<T> :: insert_first(T data)
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
}

template<class T>
void SCLL<T> :: insert_last(T data)
{
    struct node<T>* newn = new node<T>;
    struct node<T>* temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void SCLL<T> :: insert_position(int position, T data)
{
    int nodeCnt = count();
    int iCnt = 0;
    struct node<T>* newn = new node<T>;
    struct node<T>* temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

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
        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void SCLL<T> :: delete_first()
{
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        First = (First)->next;
        free((First)->prev); 
        (First)->prev = NULL;
    }
}

template<class T>
void SCLL<T> :: delete_last()
{
    struct node<T>* temp = First;

    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        free(temp->next); 
        temp->next = NULL;
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
        temp2->prev = temp1;
        free(temp2);
    }
}

template<class T>
void SCLL<T> :: display()
{
    struct node<T>* temp = First;
    cout<<"Elements of Linked List : "<<"\n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int SCLL<T> :: count()
{
    struct node<T>* temp = First;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return (count);
}
