//Insertion at Begining, End , Position for Doubly Circular Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;

void create()
{
    int n;
    printf("Enter the number of elements in Linked List :");
    scanf("%d", &n);
    struct node *newnode;
    head = 0;
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        if (head == 0)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
    }
}


void display()
{
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("List Empty...\n");
    }
    else
    {
        do
        {
            printf("Element :%d \n", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

void insertAtBeginning(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Data for beginning: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        head->next = head;
        head->prev = head;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void insertAtEnd(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Data for End: ");
    scanf("%d", &newnode->data);
    if (head == 0)
    {
        head = tail = newnode;
        head->next = head;
        head->prev = head;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev=newnode;
        tail = newnode;
    }
}

void insertAtPosition(){
    int n, i;
    i = 0;
    struct node *newnode, *temp;

    printf("Enter position: \n");
    scanf("%d", &n);
    if (n==1)
    {
        insertAtBeginning();
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Data for node: ");
        scanf("%d", &newnode->data);
        while (i<n-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        (temp->next)->prev = newnode;
        temp->next = newnode;
    }
    
}

int main()
{
    create();
    display();
}