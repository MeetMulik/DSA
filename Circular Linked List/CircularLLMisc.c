//Deletion at Beginning , End  , Position

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
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
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
    }
}
void display()
{
    struct node *temp = head;

    if (head != NULL)
    {
        do
        {
            printf("Element :%d \n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void countNodes()
{
    struct node *temp = head;
    int i = 1;

    if (head != NULL)
    {
        while (temp != tail)
        {
            i++;
            temp = temp->next;
        }
    }
    printf("Number of nodes are : %d \n", i);
}

void search()
{   
    int data;
    printf("Enter the element to search:  \n");
    scanf("%d" , &data);
    struct node *ptr = head;
    int i = 1;
    bool found = false;

    while (ptr->next != head)
    {

        if (ptr->data == data)
        {
            printf("Element found at pos: %d", i);
            found = true;
        }
        
        ptr = ptr->next;
        i++;
    }
    if (tail->data==data)
    {   
        found=true;
        printf("Element found at %d \n", i);
    }

    if (!found)
    {
        printf("Element not found");
    }
}


int main()
{
    create();
    display();
    countNodes();
    search();
    return 0;
}