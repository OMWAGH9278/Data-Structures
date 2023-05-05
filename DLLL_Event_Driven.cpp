#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SCLL
{
    public:
        PNODE First;

        SCLL();

        void insert_first(int data);
        void insert_last(int data);
        void insert_position(int position, int data);

        void delete_first();
        void delete_last();
        void delete_position(int position);

        void display();
        int count();
};

int main(void)
{
    SCLL sobj;
    int choice = 0, element = 0, element_count = 0, position = 0; 

    while(1)
    {
        cout<<"-------------------------------------------------"<<"\n\n";

        cout<<"INSIDE DOUBLY LINEAR LINKED LIST"<<"\n\n";

        cout<<"Press 1 : Insert element at first position"<<"\n"<<
                "Press 2 : Insert element at last position"<<"\n"<<
                "Press 3 : Insert element at input position"<<"\n"<<
                "Press 4 : Delete element at first position"<<"\n"<<
                "Press 5 : Delete element at last position"<<"\n"<<
                "Press 6 : Delete element at input position"<<"\n"<<
                "Press 7 : Display elements of Linked List"<<"\n"<<
                "Press 8 : Count elements in Linked List"<<"\n"<<
                "Press 9 : Exit Application"<<"\n";

        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter element"<<"\n";
                cin>>element;
                sobj.insert_first(element);
                break;
            }
            case 2:
            {
                cout<<"Enter element"<<"\n";
                cin>>element;
                sobj.insert_last(element);
                break;
            }
            case 3:
            {
                cout<<"Enter position"<<"\n";
                cin>>position;
                cout<<"Enter element"<<"\n";
                cin>>element;
                sobj.insert_position(position, element);
                break;
            }
            case 4:
            {
                sobj.delete_first();
                break;
            }
            case 5:
            {
                sobj.delete_last();
                break;
            }
            case 6:
            {
                cout<<"Enter position"<<"\n";
                cin>>position;
                sobj.delete_position(position);
                break;
            }
            case 7:
            {
                sobj.display();
                break;
            }
            case 8:
            {
                element_count = sobj.count();
                cout<<"Number of elements in Linked List : "<<element_count<<"\n";
                break;
            }
            case 9:
            {
                cout<<"Thank You For Using Application!!"<<"\n";
                return (0);
            }
        }
    }

    return (0);
}

SCLL :: SCLL()
{
    First = NULL;
}

void SCLL :: insert_first(int data)
{
    PNODE newn = new NODE;

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

void SCLL :: insert_last(int data)
{
    PNODE newn = new NODE;
    PNODE temp = NULL;

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

void SCLL :: insert_position(int position, int data)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE newn = new NODE;
    PNODE temp = NULL;

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

void SCLL :: delete_first()
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

void SCLL :: delete_last()
{
    PNODE temp = First;

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

void SCLL :: delete_position(int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

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

void SCLL :: display()
{
    PNODE temp = First;
    cout<<"Elements of Linked List : "<<"\n";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int SCLL :: count()
{
    PNODE temp = First;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return (count);
}
