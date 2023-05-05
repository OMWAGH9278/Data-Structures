#include <iostream>
using namespace std;

template <class T>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

template <class T>
class DCLL
{
    public:
        struct node<T>* First;
        struct node<T>* Last;

        DCLL();

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
    DCLL<int>  dobj;
    int choice = 0, element = 0, element_count = 0, position = 0;

    while(1)
    {
        cout<<"---------------------------------------------------"<<"\n";

        cout<<"Press 1 : Insert element at first position"<<"\n"<<
                "Press 2 : Insert element at last position"<<"\n"<<
                "Press 3 : Insert element at input position"<<"\n"<<
                "Press 4 : Delete element at first position"<<"\n"<<
                "Press 5 : Delete element at last position"<<"\n"<<
                "Press 6 : Delete element at input position"<<"\n"<<
                "Press 7 : Display elements of Linked List"<<"\n"<<
                "Press 8 : Count elements of Linked List"<<"\n"<<
                "Press 9 : Exit Application"<<"\n";

        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter element"<<"\n";
                cin>>element;
                dobj.insert_first(element);
                break;
            }
            case 2:
            {
                cout<<"Enter element"<<"\n";
                cin>>element;
                dobj.insert_last(element);
                break;
            }
            case 3:
            {
                cout<<"Enter position"<<"\n";
                cin>>position;
                cout<<"Enter element"<<"\n";
                cin>>element;
                dobj.insert_position(position, element);
                break;
            }
            case 4:
            {
                dobj.delete_first();
                break;
            }
            case 5:
            {
                dobj.delete_last();
                break;
            }
            case 6:
            {
                cout<<"Enter position"<<"\n";
                cin>>position;
                dobj.delete_position(position);
                break;
            }
            case 7:
            {
                dobj.display();
                break;
            }
            case 8:
            {
                int element_count = dobj.count();
                cout<<"Number of elements in Linked List are : "<<element_count;
                break;
            }
            case 9:
            {
                cout<<"Thank You for using application!!"<<"\n";
                return (0);
            }
        }
    }

    return (0);
}

template <class T>
DCLL<T> :: DCLL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DCLL<T>  :: insert_first(T data)
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
    (Last)->next = First;
    (First)->prev = Last;
}

template <class T>
void DCLL<T>  :: insert_last(T data)
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        (Last)->next = newn;
        Last = newn;
    }
    (Last)->next = First;
    (First)->prev = Last;
}

template <class T>
void DCLL<T>  :: insert_position(int position, T data)
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
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

template <class T>
void DCLL<T> :: delete_first()
{
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = (First)->next;
        delete (First)->prev;
        (Last)->next = First;
        (First)->prev = Last;
    }
}

template <class T>
void DCLL<T>  :: delete_last()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = (Last)->prev;
        delete (Last)->next;
        (Last)->next = First;
        (First)->prev = Last;
    }
}

template <class T>
void DCLL<T>  :: delete_position(int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    struct node<T>* temp = NULL;

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
        temp = First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}

template <class T>
void DCLL<T>  :: display()
{
    struct node<T>* temp = First;
    cout<<"Elements of Linked List are : "<<"\n";
    do
    {
        printf("| %d | -> ", temp->data);
        temp = temp->next;
    }
    while(temp != Last->next);
    cout<<"NULL"<<"\n";
}

template <class T>
int DCLL<T> :: count()
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
