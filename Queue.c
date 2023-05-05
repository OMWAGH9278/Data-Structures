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

bool isQueueEmpty(PNODE First);
void enQueue(PPNODE First, int data);
int deQueue(PPNODE First);
void display(PNODE First);
int count(PNODE First);

int main(void)
{
    PNODE Head = NULL;
    int iRet = 0;

    enQueue(&Head, 11);
    enQueue(&Head, 21);
    enQueue(&Head, 51);
    enQueue(&Head, 101);

    display(Head);

    iRet = deQueue(&Head);
    printf("%d is dequeued from queue\n", iRet);
    iRet = deQueue(&Head);
    printf("%d is dequeued from queue\n", iRet);

    display(Head);

    return (0);
}

bool isQueueEmpty(PNODE First)
{
    int nodeCnt = count(First);
    if(nodeCnt == 0)
        return true;
    else
        return false;
}

void enQueue(PPNODE First, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *First;

    newn->data = data;
    newn->next = NULL;

    if(*First == NULL)
        *First = newn;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = newn;
    }

    printf("%d is enQueued successfully\n", data);
}

int deQueue(PPNODE First)
{
    PNODE temp = NULL;
    int value = (*First)->data;

    if(*First == NULL)
    {
        printf("Queue is empty\n");
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
    printf("Elements of queue are:\n");
    while(First != NULL)
    {
        printf("| %d |-> ", First->data);
        First = First->next;
    }

    printf("NULL\n");
}

int count(PNODE First)
{
    int nodeCnt = 0;
    while(First != 0)
    {
        nodeCnt++;
        First = First->next;
    }

    return (nodeCnt);
}