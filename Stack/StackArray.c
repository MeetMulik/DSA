#include <stdio.h>
#include <stdlib.h>

#define N 50

int stack[N];
int top = -1;

void push(int x)
{
    if (top == N - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed to Stack\n", x);
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        int item = stack[top];
        top--;
        printf("Popped: %d\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top Element: %d\n", stack[top]);
    }
}

void display()
{
    int i;
    printf("Displaying Stack: \n");
    for (int i = top; i >= 0; i--)
    {
        printf("Element :%d \n", stack[i]);
    }
}

int main()
{
    push(6);
    push(9);
    push(1);
    display();
    push(7);
    peek();
    pop();
    push(11);
    display();
    return 0;
}