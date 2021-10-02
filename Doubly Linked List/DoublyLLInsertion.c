//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *tail;

void create()
{
    int a;
    head = NULL;
    printf("Enter the number of elements in LL : ");
    scanf("%d", &a);

    for (int i = 0; i < a; i++)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}
void insertAtBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data for beginning node: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        printf("Element inserted at beginning..\n");
    }
}

void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data for End node: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        printf("Element inserted at End..\n");
    }
}

int countNodes()
{
    int i = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    printf("Number of nodes: %d \n", i);
    return i;
}

void insertAtPosition()
{
    int n;
    int i = 1;
    int count = countNodes();

    printf("Enter position: \n");
    scanf("%d", &n);

    struct node *newnode, *temp;
    temp = head;

    if (n == 1)
    {
        insertAtBeginning();
    }
    else if (n >= count)
    {
        insertAtEnd();
    }
    
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data for node: ");
        scanf("%d", &newnode->data);
        while (i < n - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        (newnode->next)->prev = newnode;
        printf("Element inserted at Position..\n");
    }
}



void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("Element: %d \n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    create();
    insertAtPosition();
    display();
    return 0;
}