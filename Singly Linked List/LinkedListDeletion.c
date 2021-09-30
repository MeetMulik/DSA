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

void deleteFirstElement()
{

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {

        struct node *ptr = head;
        printf("Element Deleted: %d\n", head->data);
        head = head->next;
        free(ptr);
        printf("Updated List is:\n");
        display();
    }
}



void deleteAtEnd()
{
    struct node *p = head;
    struct node *q = head->next;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted \n");
    }
    else
    {

        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        printf("Element Deleted: %d\n", q->data);
        printf("Updated List is:\n");
        display();
        free(q);
    }
}

void deleteAfterValue(int value)
{

    struct node *ptr, *p;
    ptr = head;

    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        while (ptr->data != value)
        {
            ptr = ptr->next;
            p = ptr->next;
        }

        ptr->next = p->next;
        printf("Element deleted: %d\n", p->data);
        free(p);
    }
    
}
void deleteBeforeValue(int value)
{
    if(head==NULL){
        printf("\nList is empty");
    }
    else{
        struct node *ptr, *p;
        ptr = head;
        p=head->next;

        while ((p->next)->data != value)
        {
            p=p->next;
            ptr=ptr->next;
        }

        ptr->next = p->next;
        printf("Element deleted: %d\n", p->data);
        free(p);
    }
    

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

    
}

