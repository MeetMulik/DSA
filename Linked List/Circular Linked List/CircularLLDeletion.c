//Deletion at Beginning , End  , Position

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


int countNodes()
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
    return i;
}


void deleteAtBeginning(){
    struct node *temp;
    temp = head;

    if (head==NULL)
    {
        printf("List Empty!\n");
    }
    else if(head->next==head){
        head = NULL;
        free(head);
        printf("1 present node deleted");
    }
    else{
        while (temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        printf("Start node deleted..\n");
        
    }

}

    // USING TAIL
// void deleteAtBeginning()
// {
//     struct node *temp;
//     temp = head;

//     if (head == NULL)
//     {
//         printf("List Empty!\n");
//     }
//     else if (head->next == head)
//     {
//         head = NULL;
//         free(head);
//         printf("1 present node deleted");
//     }
//     else
//     {
//         tail->next = head->next;
//         free(head);
//         head = tail->next;
//         printf("Start node deleted..\n");
//     }
// }

void deleteAtEnd(){

    struct node *temp, *prev;
    temp = head;

    if (head == NULL)
    {
        printf("List Empty!\n");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("1 present node deleted");
    }
    else{
        while (temp->next!=head)
        {
            prev =  temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        free(temp);
        printf("End node deleted..\n");
        }
}

void deleteAtPosition()
{
    int n, i, nodes;
    i = 0;
    nodes = countNodes();

    printf("Enter position: \n");
    scanf("%d", &n);

    if (n == 1)
    {
        deleteAtBeginning();
    }
    
    else
    {
        struct node *ptr, *temp;
        temp = head;
    
        while (i < n - 1)
        {   
            ptr = temp;
            temp = temp->next;
            i++;
        }
        ptr->next = temp->next;
        free(temp);
        printf("Requested node deleted..\n");
    }
}

int main()
{
    create();
    display();
    
    return 0;
}