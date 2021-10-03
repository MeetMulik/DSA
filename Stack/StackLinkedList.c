#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

struct Node *top = 0;

void push(int x)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = top;
    top = ptr;
}

void display()
{
    struct Node *temp;
    temp = top;

    if (top == 0)
    {
        printf("Stack Empty");
    }
    else
    {
        while (temp != 0)
        {

            printf("Element : %d\n", temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    if (top == 0)
    {
        printf("Stack Empty");
    }
    else
    {
        printf("Top element is : %d\n", top->data);
    }
}

void pop()
{
    struct Node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Stack Empty");
    }
    else
    {
        printf("Popped element is : %d \n", top->data);
        top = top->next;
        free(temp);
    }
}

int main()
{
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    peek();
    display();
    return 0;
}