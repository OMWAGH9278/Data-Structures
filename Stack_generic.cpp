#include <iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node* next;
};

template <class T>
class Stack
{
    public:
        struct node<T>* First;
        int iCount;

        Stack();

        bool isStackEmpty();
        void push(T data);  // Insert
        T pop();            // Delete
        void display();
};

template <class T>
Stack<T> :: Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
bool Stack<T> :: isStackEmpty()
{
    if(iCount == 0)
        return true;
    else
        return false;
}

template <class T>
void Stack<T> :: push(T data)  // InsertFirst
{
    struct node<T>* newn = new node<T>;

    newn->data = data;
    newn->next = NULL;

    if(First == NULL)
        First= newn;
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;

    cout<<data<<" gets pushed in stack successfully"<<"\n";
}

template <class T>
T Stack<T> :: pop()            // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"unable to pop element as stack is empty"<<"\n";
        return (-1);
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
void Stack<T> :: display()
{
    if(First == NULL)
        cout<<"Stack is empty"<<"\n";
    else
    {
        cout<<"Elements of stack are : "<<"\n";

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
    Stack <int>obj;

    obj.push(11);
    obj.push(21);
    obj.push(51);
    obj.push(101);

    obj.display();

    int iRet = obj.pop();
    cout<<"Poped element is : "<<iRet<<"\n";
    iRet = obj.pop();
    cout<<"Poped element is : "<<iRet<<"\n";

    obj.display();

    return (0);
}