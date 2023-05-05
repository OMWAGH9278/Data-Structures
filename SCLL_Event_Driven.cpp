#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SCLL
{
    public:
        PNODE First;
        PNODE Last;

        SCLL();

        void insert_first(int data);
        void insert_last(int data);
        void insert_position(int data, int position);

        void delete_first();
        void delete_last();
        void delete_position(int position);

        void display();
        int count();
};

int main(void)
{
    SCLL sobj;
    int choice = 0, element = 0, position = 0;

    while(1)
    {
        cout<<"------------------------------------------------------------"<<"\n";

        cout<<"Press 1 : Insert new element at first position"<<"\n"<<
                "Press 2 : Insert new element at last position"<<"\n"
                "Press 3 : Insert new element at accepted position"<<"\n"<<
                "Press 4 : Delete element at first position"<<"\n"<<
                "Press 5 : Delete element at last position"<<"\n"<<
                "Press 6 : Delete element at accepted position"<<"\n"<<
                "Press 7 : Display elements"<<"\n"<<
                "Press 8 : Count elements"<<"\n"<<
                "Press 9 : Exit Application"<<"\n";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter element:"<<"\n";
                cin>>element;
                sobj.insert_first(element);
                break;
            }
            case 2:
            {
                cout<<"Enter element:"<<"\n";
                cin>>element;
                sobj.insert_last(element);
                break;
            }
            case 3:
            {
                cout<<"Enter position:"<<"\n";
                cin>>position;
                cout<<"Enter element:"<<"\n";
                cin>>element;
                sobj.insert_position(element, position);
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
                cout<<"Enter position to delete element:"<<"\n";
                cin>>element;
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
                int element_count = sobj.count();
                cout<<"Total elements in linked list : "<<element_count<<"\n";
                break;
            }
            case 9:
            {
                cout<<"Thank you for using application!!"<<"\n";
                return (0);
            }
        }
    }
    
    return (0);
}

SCLL :: SCLL()
{
    First = NULL;
    Last = NULL;
}

void SCLL :: insert_first(int data)
{
    PNODE newn = new NODE;

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

void SCLL :: insert_last(int data)
{
    PNODE newn = new NODE;

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

void SCLL :: insert_position(int data, int position)
{
    int nodeCnt = count();
    int iCnt = 0;
    PNODE temp = NULL;

    PNODE newn = NULL;

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
        newn = new NODE;

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

void SCLL :: delete_first()
{
    PNODE temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(((First)->next == NULL))
    {
        delete (First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        First = (First)->next;
        delete (temp);
        (Last)->next = First;
    }
}

void SCLL :: delete_last()
{
    PNODE temp = NULL;
    int iCnt = 0;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(((First)->next == NULL))
    {
        delete (First);
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
        delete (temp->next);
        (Last)->next = First;
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
        delete (temp2);
    }
}

void SCLL :: display()
{
    PNODE temp = First;

    cout<<"Elements of Linked List are:"<<"\n";
    do
    {
        printf("| %d | -> ", temp->data);
        temp = temp->next;
    }
    while(temp != Last->next);
    cout<<"NULL\n"<<"\n";
}

int SCLL :: count()
{
    PNODE temp = First;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    }
    while(temp != Last->next);
    return (count);
}
