#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class Queue
{
    public:
        struct node* First;
        int iCount;

        Queue();

        bool isQueueEmpty();
        void enQueue(int data);  // Insert
        int deQueue();            // Delete
        void display();
};

Queue :: Queue()
{
    First = NULL;
    iCount = 0;
}

bool Queue :: isQueueEmpty()
{
    if(iCount == 0)
        return true;
    else
        return false;
}

void Queue :: enQueue(int data)  // InsertLast
{
    struct node* newn = new node;

    newn->data = data;
    newn->next = NULL;

    if(First == NULL)
        First= newn;
    else
    {
        struct node* temp = First;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
    iCount++;

    cout<<data<<" gets enqueued in queue successfully"<<"\n";
}

int Queue :: deQueue()            // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"unable to dequeue element as queue is empty"<<"\n";
        return (-1);
    }
    else
    {
        int value = First->data;
        struct node* temp = First;

        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

void Queue :: display()
{
    if(First == NULL)
        cout<<"Queue is empty"<<"\n";
    else
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct node* temp = First;
        while(temp != NULL)
        {
            cout<<"| "<<temp->data<<" |-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<"\n";
    }
}

int main(void)
{
    Queue obj;

    obj.enQueue(11);
    obj.enQueue(21);
    obj.enQueue(51);
    obj.enQueue(101);

    obj.display();

    int iRet = obj.deQueue();
    cout<<"Removed element is : "<<iRet<<"\n";
    iRet = obj.deQueue();
    cout<<"Removed element is : "<<iRet<<"\n";

    obj.display();

    return (0);
}