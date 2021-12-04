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

void display()
{
    struct node *ptr = head;
    while (ptr != 0)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtBeginning(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head =  ptr;
}

void insertAtIndex(int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
}

void insertAtEnd(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    
}

void insertAfterValue(int value,int data){

    struct node* ptr,*p;
    ptr = head;

    p=(struct node*)malloc(sizeof(struct node));
    p->data = data;

    while(ptr->data!=value){
        ptr=ptr->next;
    }

    p->next = ptr->next;
    ptr->next = p;

}

void insertBeforeValue(int value, int data)
{

    struct node *p,*ptr,*ptr1;
    p = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    ptr1=head->next;

    p->data = data;

    while (ptr1->data != value)
    {
        ptr = ptr->next;
        ptr1=ptr1->next;
    }

    ptr->next = p;
    p->next=  ptr1;

}

int main()
{
    int a;
    int i = 0;

    printf("Enter the number of elements in LL : ");
    scanf("%d", &a);
    head = 0;

    while (i < a)
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

    display();
   

    
}