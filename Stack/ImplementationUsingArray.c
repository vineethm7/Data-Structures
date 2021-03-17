#include <stdio.h>
int top=-1;

void push(int N, int x, int stack[])
{
    if(top>=N-1)
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop(int stack[])
{
    int i;
    if(top<=-1)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        printf("The popped elements is %d\n",stack[top]);
        top--;
    }
    
}

void peek(int stack[])
{
    if(top<=-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Element at Top of stack is %d",stack[top]);
    }
    
}

void display(int stack[])
{
    if(top>=0)
    {
        printf("The elements in STACK(Printed from Top to Bottom) \n");
        for(int i=top; i>=0; i--)
            printf("%d ",stack[i]);
    }
    else
    {
        printf("The STACK is empty\n");
    }
}
int main()
{
    int N;
    printf("Enter size of stack?\n");
    scanf("%d",&N);
    int stack[N];
    while(1)
    {
        int op;
        printf("\nEnter the Stack Operation\n1.Push\n2.Pop\n3.Top\n4.Display\n5.EXIT\n");
        scanf("%d",&op);
        if(op==1)
        {
            int x;
            printf("Enter value to be pushed into stack\n");
            scanf("%d",&x);
            push(N,x,stack);
        }
        if(op==2)
        {
            pop(stack);
        }
        if(op==3)
        {
            peek(stack);
        }
        if(op==4)
        {
            display(stack);
        }
        if(op==5)
        {
            break;
        }
    }    
}