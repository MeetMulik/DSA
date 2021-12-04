//Deletion at Begining, End , Position for Doubly Circular Linked Lists

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


void deleteAtBeginning()
{
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("List Empty for begin\n");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
        printf("Deletion Complete...\n");
        display();
    }
}

void deleteAtEnd()
{
    struct node *temp;
    temp = tail;
    if (head == 0)
    {
        printf("List Empty...\n");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
        printf("Deletion Complete...\n");
        display();
    }
}

void deleteAtPositon()
{
    int n, i;
    i = 0;
    struct node *temp;
    temp = head;

    printf("Enter position: \n");
    scanf("%d", &n);
    if (n == 1)
    {
        deleteAtBeginning();
    }
    else
    {
        while (i < n - 1)
        {
            temp = temp->next;
            i++;
        }
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        if (temp->next == head)
        {
            tail = temp->prev;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
    printf("Deletion Complete...\n");
    display();
}
int main()
{
    create();
    display();

}