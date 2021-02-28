#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *top = NULL;
void push(int x)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    node *temp;
    temp = top;
    if(top=NULL)
    {
        printf("Stack is underflow\n");
    }
    else
    {
        printf("Popped element is %d\n",top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    node *temp;
    temp = top;
    if(top==NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is: ");
        while (temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void main ()  
{  
    int choice=0;     
    printf("\n*********Stack operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");  
        printf("\nEnter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                int x;
                printf("Enter the element to be pushed: \n");
                scanf("%d",&x);
                push(x);  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....\n");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }  
        }     
    };  
}  