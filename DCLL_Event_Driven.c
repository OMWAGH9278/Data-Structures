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

void insert_first(PPNODE First, PPNODE Last, int data);
void insert_last(PPNODE First, PPNODE Last, int data); 
void insert_position(PPNODE First, PPNODE Last, int position, int data); 

void delete_first(PPNODE First, PPNODE Last);
void delete_last(PPNODE First, PPNODE Last); 
void delete_position(PPNODE First, PPNODE Last, int position); 

void display(PNODE First, PNODE Last);
int count(PNODE First, PNODE Last); 

int main(void)
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int choice = 0, element = 0, element_count = 0, position = 0;

    while(1)
    {
        printf("---------------------------------------------------\n");

        printf("Press 1 : Insert element at first position\n");
        printf("Press 2 : Insert element at last position\n");
        printf("Press 3 : Insert element at input position\n");
        printf("Press 4 : Delete element at first position\n");
        printf("Press 5 : Delete element at last position\n");
        printf("Press 6 : Delete element at input position\n");
        printf("Press 7 : Display elements of Linked List\n");
        printf("Press 8 : Count elements of Linked List\n");
        printf("Press 9 : Exit Application\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter element\n");
                scanf("%d", &element);
                insert_first(&Head, &Tail, element);
                break;
            }
            case 2:
            {
                printf("Enter element\n");
                scanf("%d", &element);
                insert_last(&Head, &Tail, element);
                break;
            }
            case 3:
            {
                printf("Enter position\n");
                scanf("%d", &position);
                printf("Enter element\n");
                scanf("%d", &element);
                insert_position(&Head, &Tail, position, element);
                break;
            }
            case 4:
            {
                delete_first(&Head, &Tail);
                break;
            }
            case 5:
            {
                delete_last(&Head, &Tail);
                break;
            }
            case 6:
            {
                printf("Enter position\n");
                scanf("%d", &position);
                delete_position(&Head, &Tail, position);
                break;
            }
            case 7:
            {
                display(Head, Tail);
                break;
            }
            case 8:
            {
                int element_count = count(Head, Tail);
                printf("Number of elements in Linked List are : %d\n", element_count);
                break;
            }
            case 9:
            {
                printf("Thank You for using application!!\n");
                return (0);
            }
        }
    }

    return (0);
}

void insert_first(PPNODE First, PPNODE Last, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void insert_last(PPNODE First, PPNODE Last, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->prev = *Last;
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last)->next = *First;
    (*First)->prev = *Last;
}

void insert_position(PPNODE First, PPNODE Last, int position, int data)
{
    int nodeCnt = count(*First, *Last);
    int iCnt = 0;
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;

    if((position < 1) && (position > nodeCnt+1))
    {
        printf("Invalid position\n");
        exit(-1);
    }

    if(position == 1)
    {
        insert_first(First, Last, data);
    }
    else if(position == nodeCnt+1)
    {
        insert_last(First, Last, data);
    }
    else
    {
        temp = *First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

void delete_first(PPNODE First, PPNODE Last)
{
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev);
        (*Last)->next = *First;
        (*First)->prev = *Last;
    }
}

void delete_last(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *Last = (*Last)->prev;
        free((*Last)->next);
        (*Last)->next = *First;
        (*First)->prev = *Last;
    }
}

void delete_position(PPNODE First, PPNODE Last, int position)
{
    int nodeCnt = count(*First, *Last);
    int iCnt = 0;
    PNODE temp = NULL;

    if((position < 1) && (position > nodeCnt))
    {
        printf("Invalid position\n");
        exit(-1);
    }

    if(position == 1)
    {
        delete_first(First, Last);
    }
    else if(position == nodeCnt)
    {
        delete_last(First, Last);
    }
    else
    {
        temp = *First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

void display(PNODE First, PNODE Last)
{
    printf("Elements of Linked List are : \n");
    do
    {
        printf("| %d | -> ", First->data);
        First = First->next;
    }
    while(First != Last->next);
    printf("NULL\n");
}

int count(PNODE First, PNODE Last)
{
    int count = 0;
    do
    {
        count++;
        First = First->next;
    }
    while(First != Last->next);

    return (count);
}
