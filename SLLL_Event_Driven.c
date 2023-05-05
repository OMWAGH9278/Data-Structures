
/*
        AUTHOR: OM MANGESH WAGH
        DATE: 25/11/2022
        GOAL: TO CREATE EVENT DRIVEN SINGLY LINEAR LINKED LIST
*/

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

void insert_first (PPNODE first, int element);
void insert_last (PPNODE first, int element);
void insert_at_position (PPNODE first, int element, int position);

void delete_first (PPNODE first);
void delete_last (PPNODE first);
void delete_at_position (PPNODE first, int position);

void display (PNODE first);
int count (PNODE first);

int main (void)
{
    PNODE head = NULL;
    int choice = 0, element = 0, position = 0, element_count = 0;

    while (1)
    {
        printf ("------------------------------------------------------------------\n");

        printf ("Press 1: Insert element at first position\n");
        printf ("Press 2: Insert element at last position\n");
        printf ("Press 3: Insert element at given position\n");
        printf ("Press 4: Delete element at first position\n");
        printf ("Press 5: Delete element at last position\n");
        printf ("Press 6: Delete element at given position\n");
        printf ("Press 7: Display elements of Linked List\n");
        printf ("Press 8: Count elements of Linked List\n");
        printf ("Press 9: Exit Application\n");
        scanf ("%d",&choice);

        switch (choice)
        {
            case 1:
                printf ("Enter element :\n");
                scanf ("%d",&element);
                insert_first (&head,element);
                break;
            case 2:
                printf ("Enter element :\n");
                scanf ("%d",&element);
                insert_last (&head,element);
                break;
            case 3:
                printf ("Enter element :\n");
                scanf ("%d",&element);
                printf ("Enter position of element :\n");
                scanf ("%d",&position);
                insert_at_position (&head,element,position);
                break;
            case 4:
                delete_first (&head);
                break;
            case 5:
                delete_last (&head);
                break;
            case 6:
                printf ("Enter position of element to delete :\n");
                scanf ("%d",&position);
                delete_at_position(&head,position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                element_count = count(head);
                printf("Elements of Linked List are : %d\n",element_count);
                break;
            case 9:
                printf ("Thank You For Using This Application :)\n");
                return 0;
            default:
                printf ("Invalid choice\n");
                break;
        }

        printf ("------------------------------------------------------------------\n");
    }
    

    return (0);
}

void display(PNODE first)
{
    printf("Elements of Linked List are :\n");
    while(first != NULL)
    {
        printf("| %d |->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int count(PNODE first)
{
    int element_count = 0;

    while(first != NULL)
    {
        element_count++;
        first = first->next;
    }
    return element_count;
}

void insert_first(PPNODE first, int element)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = element;
    newn->next = NULL;

    if(*first == NULL)
        *first = newn;
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void insert_last(PPNODE first, int element)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = NULL;

    newn->data = element;
    newn->next = NULL;

    if(*first == NULL)
        *first = newn;
    else
    {
        temp = *first;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newn;
    }
}

void insert_at_position(PPNODE first, int element, int position)
{
    int node_count = count(*first), iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((position < 1) || (position > node_count+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(position == 1)
        insert_first(first, element);
    else if(position == node_count+1)
        insert_last(first, element);
    else 
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = element;
        newn->next = NULL;

        temp = *first;
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp = temp->next;
        
        newn->next = temp->next;
        temp->next = newn;
    }
}

void delete_first(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
        return;
    else if((*first)->next == NULL)
    {
        free (*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        *first = (*first)->next;
        free (temp);
    }
}

void delete_last(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
        return;
    else if((*first)->next == NULL)
    {
        free (*first);
        *first = NULL;
    }
    else
    {
        temp = *first;
        while(temp->next->next != NULL)
            temp = temp->next;
        free (temp->next);
        temp->next = NULL;
    }
}

void delete_at_position(PPNODE first, int position)
{
    int node_count = count(*first), iCnt = 0;
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    if((position < 1) || (position > node_count))
    {
        printf("Invalid position\n");
        return;
    }

    if(position == 1)
        delete_first(first);
    else if(position == node_count)
        delete_last(first);
    else 
    {
        temp1 = *first;
        for(iCnt = 1; iCnt < (position-1); ++iCnt)
            temp1 = temp1->next;
        
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free (temp2);
    }
}