#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *newnode;
struct node *temp;

void display(){

    struct node* ptr = head;
    while (ptr!=0)
    {
        printf("Element : %d \n" , ptr->data);
        ptr= ptr->next;
    }
}

int main()
{
    int a;
    int i=0;

    
    printf("Enter the number of elements in LL : ");
    scanf("%d", &a);
    head = 0;

    while (i<a)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
    }
    temp = head;
}