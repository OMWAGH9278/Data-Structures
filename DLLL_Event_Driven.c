#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void insert_first(PPNODE First, int data);
void insert_last(PPNODE First, int data);
void insert_position(PPNODE First, int position, int data);
void delete_first(PPNODE First);
void delete_last(PPNODE First);
void delete_position(PPNODE First, int position);
void display(PNODE First);
int count(PNODE First);

int main(void)
{
    PNODE Head = NULL;
    int choice = 0, element = 0, element_count = 0, position = 0; 

    while(1)
    {
        printf("-------------------------------------------------\n\n");

        printf("INSIDE DOUBLY LINEAR LINKED LIST\n\n");

        puts("Press 1 : Insert element at first position");
        puts("Press 2 : Insert element at last position");
        puts("Press 3 : Insert element at input position");
        puts("Press 4 : Delete element at first position");
        puts("Press 5 : Delete element at last position");
        puts("Press 6 : Delete element at input position");
        puts("Press 7 : Display elements of Linked List");
        puts("Press 8 : Count elements in Linked List");
        puts("Press 9 : Exit Application");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter element\n");
                scanf("%d", &element);
                insert_first(&Head, element);
                break;
            }
            case 2:
            {
                printf("Enter element\n");
                scanf("%d", &element);
                insert_last(&Head, element);
                break;
            }
            case 3:
            {
                printf("Enter position\n");
                scanf("%d", &position);
                printf("Enter element\n");
                scanf("%d", &element);
                insert_position(&Head, position, element);
                break;
            }
            case 4:
            {
                delete_first(&Head);
                break;
            }
            case 5:
            {
                delete_last(&Head);
                break;
            }
            case 6:
            {
                printf("Enter position\n");
                scanf("%d", &position);
                delete_position(&Head, position);
                break;
            }
            case 7:
            {
                display(Head);
                break;
            }
            case 8:
            {
                element_count = count(Head);
                printf("Number of elements in Linked List : %d\n", element_count);
                break;
            }
            case 9:
            {
                printf("Thank You For Using Application!!\n");
                return (0);
            }
        }
    }

    return (0);
}

void insert_first(PPNODE First, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}

void insert_last(PPNODE First, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        temp = *First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

void insert_position(PPNODE First, int position, int data)
{
    int nodeCnt = count(*First);
    int iCnt = 0;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if((position < 1) && (position > nodeCnt+1))
    {
        puts("Invalid position");
        exit(-1);
    }

    if(position == 1)
    {
        insert_first(First, data);
    }
    else if(position == nodeCnt+1)
    {
        insert_last(First, data);
    }
    else
    {
        temp = *First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void delete_first(PPNODE First)
{
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev); 
        (*First)->prev = NULL;
    }
}

void delete_last(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        free(temp->next); 
        temp->next = NULL;
    }
}

void delete_position(PPNODE First, int position)
{
    int nodeCnt = count(*First);
    int iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((position < 1) && (position > nodeCnt))
    {
        puts("Invalid position");
        exit(-1);
    }

    if(position == 1)
    {
        delete_first(First);
    }
    else if(position == nodeCnt)
    {
        delete_last(First);
    }
    else
    {
        temp1 = *First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->prev = temp1;
        free(temp2);
    }
}

void display(PNODE First)
{
    printf("Elements of Linked List : \n");
    while(First != NULL)
    {
        printf("| %d | -> ", First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int count(PNODE First)
{
    int count = 0;

    while(First != NULL)
    {
        count++;
        First = First->next;
    }

    return (count);
}
