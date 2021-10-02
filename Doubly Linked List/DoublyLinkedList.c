//Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *newnode, *head;

void create()
{   
    int a;
    head = NULL;
    printf("Enter the number of elements in LL : ");
    scanf("%d", &a);

    struct node *temp;

    for (int i = 0; i < a; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head =temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void display(){
    struct node *temp;
    temp = head;
    while (temp!= NULL)
    {   
        printf("Element: %d \n", temp->data);
        temp=temp->next;
    }
    
}
int main()
{
    create();
    display();
    return 0;
}