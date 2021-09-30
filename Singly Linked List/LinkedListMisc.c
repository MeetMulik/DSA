//Reverse , CountNodes ,Search,Sort functions included

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

void countNodes()
{

    struct node *ptr = head;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    printf("Number of nodes = %d", count);
}
void search(int data)
{
    struct node *ptr = head;
    int i = 0;
    bool found = false;

    while (ptr != NULL)
    {
       
        if (ptr->data == data)
        {
            printf("Element found at pos: %d", i);
            found = true;
        }
        ptr = ptr->next;
        i++;
    }

    if (!found)
    {
        printf("Element not found");
    }
}
void sort(){
    struct node *ptr, *cpt;
    int temp;
    ptr = head;

    while (ptr->next!=NULL)
    {
        cpt = ptr->next;
        while(cpt!=NULL){
            if(ptr->data > cpt->data){

                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt=cpt->next;

        }
        ptr=ptr->next;
    }
    printf("Sorted LL : \n");
    display();
}
void reverse()
{

    struct node *currentnode, *prevnode, *nextnode;
    prevnode = 0;
    currentnode = head;
    nextnode = head;
    while (nextnode != 0)
    {
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
    printf("Linked List reversal complete\n");
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
    // reverse();
    sort();
    // display();

}