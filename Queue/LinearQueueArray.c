#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
void enqueue();
void dequeue ();
void display();
void peek();
int front = -1, rear = -1;
int queue[maxsize];
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n*******Menu********\n");
       
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Peek\n5.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Choice!\n");
        }
    }
}
void enqueue()
{
    int item;
    printf("Enter the element: \n");
    scanf("%d", &item);
    if (rear == maxsize - 1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted ");
}
void dequeue ()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
            printf("Deleted!\n");
        }
        else
        {   
          printf("Value deleted: %d \n",queue[front]);
            front = front + 1;
        }
    }
}

void display()
{
    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nValues...\n");
        for (i = front; i <= rear; i++)
        {
            printf("Element: %d\n", queue[i]);
        }
    }
}

void peek(){
    if (front == -1 && rear == -1)
    {

        printf("Queue is Empty!\n");
    }
    else
    {
        printf("First Element:%d\n", queue[front]);
    }
}