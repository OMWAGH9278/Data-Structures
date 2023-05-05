#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

bool isStackEmpty();
void push(PPNODE First, int data);
int pop(PPNODE First);

void display(PNODE First);
int count(PNODE First);

int main(void)
{
    PNODE Head = NULL;
    int iRet = 0;

    push(&Head, 101);
    push(&Head, 51);
    push(&Head, 21);
    push(&Head, 11);

    display(Head);

    iRet = pop(&Head);
    printf("%d is the poped element\n", iRet);

    iRet = pop(&Head);
    printf("%d is the poped element\n", iRet);

    return (0);
}

bool isStackEmpty(PNODE First)
{
    int iNodeCnt = count(First);

    if(iNodeCnt == 0)
        return true;
    else
        return false;
}

void push(PPNODE First, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;

    if(*First == NULL)
        *First = newn;
    else
    {
        newn->next = *First;
        *First = newn;
    }
    printf("%d is pushed in stack successfully\n", data);
}

int pop(PPNODE First)
{
    PNODE temp = NULL;
    int value = (*First)->data;

    if(*First == NULL)
    {
        printf("Stack is empty\n");
        return (-1);
    }
    else
    {
        temp = *First;
        *First = (*First)->next;
        free (temp);
    }

    return (value);
}

void display(PNODE First)
{
    printf("Elements of stack are:\n");
    while(First != NULL)
    {
        printf("| %d |-> ", First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int count(PNODE First)
{
    int iCount = 0;

    while(First != NULL)
    {
        ++iCount;
        First = First->next;
    }
    return (iCount);
}