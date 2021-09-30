//Insertion at Beginning , End  , Position

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

    if (head != NULL)
    {
        do
        {
            printf("Element :%d \n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void insertAtBeginning(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: \n");
    scanf("%d", &newnode->data);
    
    if (tail==0)
    {
        tail=newnode;
        tail->next= newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
    head = newnode;
    printf("Insertion Complete...\n");
    
}

void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: \n");
    scanf("%d", &newnode->data);

    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    tail = newnode;
    printf("Insertion Complete...\n");
}


int countNodes(){
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
    return i;
}

void insertAtPosition(){
    int n,i , nodes;
    i=0;
    nodes =countNodes();
    
    printf("Enter position: \n");
    scanf("%d", &n);

    if(n==1){
        insertAtBeginning();
    }
    else if(n>nodes){
        insertAtEnd();
    }
    else{
        struct node *newnode, *temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data: \n");
        scanf("%d", &newnode->data);

        while (i<n-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Insertion Complete...\n");
    }
    
}

int main()
{
    create();
    display();
    
    return 0;
}   