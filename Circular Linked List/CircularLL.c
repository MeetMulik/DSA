#include <stdio.h>
#include <stdlib.h>

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

    if(head != NULL){
        do
        {
            printf("Element :%d \n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    
}

int main()
{
    create();
    display();
    return 0;
}