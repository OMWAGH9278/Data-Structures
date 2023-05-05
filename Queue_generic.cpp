#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node* next;
};

template <class T>
class Queue
{
    public:
        struct node<T>* First;
        int iCount;

        Queue();

        bool isQueueEmpty();
        void enQueue(T data);  // Insert
        T deQueue();            // Delete
        void display();
};

template <class T>
Queue<T> :: Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Queue<T> :: isQueueEmpty()
{
    if(iCount == 0)
        return true;
    else
        return false;
}

template <class T>
void Queue<T> :: enQueue(T data)  // InsertLast
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;

    if(First == NULL)
        First= newn;
    else
    {
        struct node<T>* temp = First;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
    iCount++;

    cout<<data<<" gets enqueued in queue successfully"<<"\n";
}

template <class T>
T Queue<T> :: deQueue()            // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"unable to dequeue element as queue is empty"<<"\n";
        return (T)(-1);
    }
    else
    {
        T value = First->data;
        struct node<T>* temp = First;

        First = First->next;
        delete temp;

        iCount--;
        return value;
    }
}

template <class T>
void Queue<T> :: display()
{
    if(First == NULL)
        cout<<"Queue is empty"<<"\n";
    else
    {
        cout<<"Elements of Queue are : "<<"\n";

        struct node<T>* temp = First;
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
    Queue <int>obj;

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