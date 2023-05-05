#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void insert_first(PPNODE First, PPNODE Last, int data);
void insert_last(PPNODE First, PPNODE Last, int data);
void insert_position(PPNODE First, PPNODE Last, int data, int position);
void delete_first(PPNODE First, PPNODE Last);
void delete_last(PPNODE First, PPNODE Last);
void delete_position(PPNODE First, PPNODE Last, int position);
void display(PNODE First, PNODE Last);
int count(PNODE First, PNODE Last);

int main(void)
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int choice = 0, element = 0, position = 0;

    while(1)
    {
        puts("------------------------------------------------------------");

        printf("Press 1 : Insert new element at first position\n");
        printf("Press 2 : Insert new element at last position\n");
        printf("Press 3 : Insert new element at accepted position\n");
        printf("Press 4 : Delete element at first position\n");
        printf("Press 5 : Delete element at last position\n");
        printf("Press 6 : Delete element at accepted position\n");
        printf("Press 7 : Display elements\n");
        printf("Press 8 : Count elements\n");
        printf("Press 9 : Exit Application\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter element:\n");
                scanf("%d", &element);
                insert_first(&Head, &Tail, element);
                break;
            }
            case 2:
            {
                printf("Enter element:\n");
                scanf("%d", &element);
                insert_last(&Head, &Tail, element);
                break;
            }
            case 3:
            {
                printf("Enter position:\n");
                scanf("%d", &position);
                printf("Enter element:\n");
                scanf("%d", &element);
                insert_position(&Head, &Tail, element, position);
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
                printf("Enter position to delete element:\n");
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
                printf("Total elements in linked list : %d\n", element_count);
                break;
            }
            case 9:
            {
                printf("Thank you for using application!!\n");
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

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
    (*Last)->next = *First;
}

void insert_last(PPNODE First, PPNODE Last, int data)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = data;
    newn->next = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
    }
    (*Last)->next = *First;
}

void insert_position(PPNODE First, PPNODE Last, int data, int position)
{
    int nodeCnt = count(*First, *Last);
    int iCnt = 0;
    PNODE temp = NULL;

    PNODE newn = NULL;

    if((position < 1) && (position > nodeCnt+1))
    {
        puts("Invalid position");
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
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = data;
        newn->next = NULL;

        temp = *First;
        for(iCnt = 1; iCnt < position-1; ++iCnt)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void delete_first(PPNODE First, PPNODE Last)
{
    PNODE temp = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(((*First)->next == NULL))
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        temp = *First;
        *First = (*First)->next;
        free(temp);
        (*Last)->next = *First;
    }
}

void delete_last(PPNODE First, PPNODE Last)
{
    PNODE temp = NULL;
    int iCnt = 0;

    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if(((*First)->next == NULL))
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        temp = *First;

        while(temp->next != *Last)
        {
            temp = temp->next;
        }

        *Last = temp;
        free(temp->next);
        (*Last)->next = *First;
    }
}

void delete_position(PPNODE First, PPNODE Last, int position)
{
    int nodeCnt = count(*First, *Last);
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
        delete_first(First, Last);
    }
    else if(position == nodeCnt)
    {
        delete_last(First, Last);
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
        free(temp2);
    }
}

void display(PNODE First, PNODE Last)
{
    puts("Elements of Linked List are:");
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
    PNODE First_Element = First;
    do
    {
        count++;
        First = First->next;
    }
    while(First != Last->next);
    return (count);
}
