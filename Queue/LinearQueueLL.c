#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue()
{
    int x;
    printf("Enqueue data: \n");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }

    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{

    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("Queue Empty");
    }
    else
    {
        temp = front;
        while (temp != 0)
        {
            printf("Element: %d \n", temp->data);
            temp = temp->next;
        }
    }
}

void dequeue()
{

    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("Queue Empty\n");
    }
    else
    {

        printf("%d is popped\n", front->data);
        front = front->next;
        free(temp);
    }
}

void peek()
{

    if (front == 0 && rear == 0)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("%d is the value at the front\n", front->data);
    }
}

int main()
{


    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    peek();
    display();
    return 0;
}