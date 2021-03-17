#include <stdio.h>
#include <string.h>
#define size 20
int top = -1;
char stack[size];

int mystrlen(char *C)
{
    int count=0;
    while(*C!='\0')
    {
        count++;
        C++;
    }
    return count;
}

char push(char ch)
{
    if(top==(size-1))
    {
        printf("Stack is Overflow\n");
    }    
    else
    {
        stack[++top]=ch;
    }    
}

char pop()
{
    if(top==-1)
    {
        printf("Stack is Underflow\n");
    }    
    else
    {
        return stack[top--];
    }    
}

void Reverse(char *C, int l)
{
    for(int i=0;i<l;i++)
    {
        push(C[i]);
    }
    for(int i=0;i<l;i++)
    {
        C[i] = pop();
    }
}

int main()
{
    char C[50];
    printf("Enter A String:\n");
    scanf("%[^\n]",C);
    int l = mystrlen(C);
    printf("Length Of String is %d\n",l);
    Reverse(C,l);
    printf("Reversed String is : %s\n",C);
}
