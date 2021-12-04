//Functions for Doubly Circular Linked Lists

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void countNodes(){
    int i=1;
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("List Empty...\n");
    }
    else
    {
        while(temp!=tail){
            i++;
            temp = temp->next;
        }
        printf("Nodes : %d\n", i);
    }
}

void search(){
    struct node *temp;
    temp = head;
    int data;
    int i = 1;
    printf("Enter the element to search:  \n");
    scanf("%d", &data);
    bool found = false;
    if (head == 0)
    {
        printf("List Empty...\n");
    }
    else
    {
        while (temp != tail)
        {
            if (temp->data == data)
            {
                printf("Element found at pos: %d \n", i);
                found = true;
            }
            i++;
            temp = temp->next;
        }
        if (tail->data==data)
        {
            found = true;
            printf("Element found at pos: %d \n", i);
        }
        
    }

    if (!found)
    {
        printf("Element not found\n");
    }
}

int main()
{
    create();
    countNodes();
    search();
    display();
}