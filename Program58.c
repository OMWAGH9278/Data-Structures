#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertLast(PPNODE First, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));  // 1

    PNODE temp = *First;

    newn->data = No;
    newn->next = NULL;

    if(*First == NULL)  // If linked list is empty
    {
        *First = newn;
    }
    else  // If linked list contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

void Display(PNODE First)
{
    printf("Elements from Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |-> ",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

bool CheckPerfect(int iNo)
{
    int iSum = 0, iCnt = 0;
    int iTemp = iNo;

    for(iCnt = 1; iCnt <= iNo/2; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    return (iSum == iTemp);
}

void DisplayPerfect(PNODE First)
{
    while(First != NULL)
    {
        if(CheckPerfect(First->data) == true)
        {
            printf("%d is a perfect number\n",First->data);
        }
        First = First->next;
    }
}

int main()
{
    PNODE Head = NULL;

    InsertLast(&Head, 11);
    InsertLast(&Head, 28);
    InsertLast(&Head, 51);
    InsertLast(&Head, 496);  // InsertFirst(60, 496);
    InsertLast(&Head, 111);  // InsertFirst(60, 111);
    InsertLast(&Head, 8128);

    DisplayPerfect(Head);

    return 0;
}