#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int No)
{

}

void Display(PNODE First)
{

}

int main()
{
    PNODE Head = NULL;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    Display(Head);

    return 0;
}

/*
    Functions:

        void InsertFirst(PPNODE First, int No)
        void InsertLast(PPNODE First, int No)
        void InsertAtPos(PPNODE First, int No, int Pos)

        void DeleteFirst(PPNODE First)
        void DeleteLast(PPNODE First)
        void DeleteAtPos(PPNODE First, int Pos)

        void Display(PNODE First)
        int Count(PNODE First)
*/
//////////////////////////////////////////////
/*
    Inside main():

        InsertFirst(&Head,11)  // Call By Address
        InsertLast(&Head,11)  // Call By Address
        InsertAtPos(&Head,5)  // Call By Address

        DeleteFirst(&Head)  // Call By Address
        DeleteLast(&Head)  // Call By Address
        DeleteAtPos(&Head)  // Call By Address

        Display(Head)  // Call By Value
        Count(Head)  // Call By Value
*/