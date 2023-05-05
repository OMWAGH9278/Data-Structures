
/*
        AUTHOR: OM MANGESH WAGH
        DATE: 25/11/2022
        GOAL: TO CREATE EVENT DRIVEN SINGLY LINEAR LINKED LIST
*/

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLinear
{
    public:
        PNODE first;
        int count;

        SinglyLinear();

        void insert_first (int element);
        void insert_last (int element);
        void insert_at_position (int element, int position);

        void delete_first ();
        void delete_last ();
        void delete_at_position (int position);

        void display ();
};

int main (void)
{
    SinglyLinear obj;
    int choice = 0, element = 0, position = 0, element_count = 0;

    while (1)
    {
        cout<<"-----------------------------------------------------------"<<"\n";

        cout<<"Press 1: Insert element at first position"<<"\n";
        cout<<"Press 2: Insert element at last position"<<"\n";
        cout<<"Press 3: Insert element at given position"<<"\n";
        cout<<"Press 4: Delete element at first position"<<"\n";
        cout<<"Press 5: Delete element at last position"<<"\n";
        cout<<"Press 6: Delete element at given position"<<"\n";
        cout<<"Press 7: Display elements of Linked List"<<"\n";
        cout<<"Press 8: Count elements of Linked List"<<"\n";
        cout<<"Press 9: Exit Application"<<"\n";

        cin>>choice;

        switch (choice)
        {
            case 1:
                cout<<"Enter element :"<<"\n";
                cin>>element;
                obj.insert_first (element);
                break;
            case 2:
                cout<<"Enter element :"<<"\n";
                cin>>element;
                obj.insert_last (element);
                break;
            case 3:
                cout<<"Enter element :"<<"\n";
                cin>>element;
                cout<<"Enter position of element :"<<"\n";
                cin>>position;
                obj.insert_at_position (element,position);
                break;
            case 4:
                obj.delete_first ();
                break;
            case 5:
                obj.delete_last ();
                break;
            case 6:
                cout<<"Enter position of element to delete:"<<"\n";
                cin>>position;
                obj.delete_at_position(position);
                break;
            case 7:
                obj.display();
                break;
            case 8:
                element_count = obj.count;
                cout<<"Number of nodes in Linked List are: "<<element_count<<"\n";
                break;
            case 9:
                cout<<"Thank You For Using This Application :)"<<"\n";
                return 0;
            default:
                cout<<"Invalid choice"<<"\n";
                break;
        }
    }

    return (0);
}

SinglyLinear :: SinglyLinear()
{
    first = NULL;
    count = 0;
}

void SinglyLinear :: display()
{
    cout<<"Elements of Linked List are: "<<"\n";
    PNODE temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

void SinglyLinear :: insert_first(int element)
{
    PNODE newn = new NODE;

    newn->data = element;
    newn->next = NULL;

    if(first == NULL)
        first = newn;
    else
    {
        newn->next = first;
        first = newn;
    }
    count++;
}

void SinglyLinear :: insert_last(int element)
{
    PNODE newn = new NODE;
    PNODE temp = NULL;

    newn->data = element;
    newn->next = NULL;

    if(first == NULL)
        first = newn;
    else
    {
        temp = first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
    count++;
}

void SinglyLinear :: insert_at_position(int element, int position)
{
    int node_count = count, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((position < 1) || (position > node_count+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
        insert_first(element);
    else if(position == node_count+1)
        insert_last(element);
    else 
    {
        newn = new NODE;

        newn->data = element;
        newn->next = NULL;

        temp = first;
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp = temp->next;
        
        newn->next = temp->next;
        temp->next = newn;

        count++;
    }
}

void SinglyLinear :: delete_first()
{
    PNODE temp = NULL;

    if(first == NULL)
        return;
    else if((first)->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    count--;
}

void SinglyLinear :: delete_last()
{
    PNODE temp = NULL;

    if(first == NULL)
        return;
    else if((first)->next == NULL)
    {
        free (first);
        first = NULL;
    }
    else
    {
        temp = first;
        while(temp->next->next != NULL)
            temp = temp->next;
        free (temp->next);
        temp->next = NULL;
    }
    count--;
}

void SinglyLinear :: delete_at_position(int position)
{
    int node_count = count, iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((position < 1) || (position > node_count))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(position == 1)
        delete_first();
    else if(position == node_count)
        delete_last();
    else 
    {
        temp1 = first;
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp1 = temp1->next;
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        count--;
    }
}