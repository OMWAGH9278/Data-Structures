#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class Stack
{
    public:
        struct node* First;
        int iCount;

        Stack();

        bool isStackEmpty();
        void push(int data);  // Insert
        int pop();            // Delete
        void display();
};

Stack :: Stack()
{
    First = NULL;
    iCount = 0;
}

bool Stack :: isStackEmpty()
{
    if(iCount == 0)
        return true;
    else
        return false;
}

void Stack :: push(int data)  // InsertFirst
{
    struct node* newn = new node;

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

int Stack :: pop()            // DeleteFirst
{
    if(First == NULL)
    {
        cout<<"unable to pop element as stack is empty"<<"\n";
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

void Stack :: display()
{
    if(First == NULL)
        cout<<"Stack is empty"<<"\n";
    else
    {
        cout<<"Elements of stack are : "<<"\n";

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
    Stack obj;

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