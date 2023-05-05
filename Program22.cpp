#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
        PNODE First;  // Characteristics :

        SinglyLL();  // Behaviours :

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertPosition(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeletePosition(int ipos);

        void Display();
        void Count();
};

int main()
{
    SinglyLL obj;



    return 0;
}