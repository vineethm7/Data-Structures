#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *front = NULL;
node *rear = NULL;
void enqueue(int x)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue()
{
    node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is Empty\n");
    }
    else if(front==rear)
    {
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else
    {
        printf("Dequeued element is %d\n",front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek()
{
    if(front == NULL && rear == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Element at front of queue is: %d",front->data);
    }
}

void display()
{
    node *temp;
    temp = front;
    if(front == NULL && rear == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is: ");
        while (temp->next!=front)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void main ()  
{  
    int choice=0;     
    printf("\n*********Circular Queue operations using linked list*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 5)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit");  
        printf("\nEnter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                int x;
                printf("Enter the element to be enqueued: \n");
                scanf("%d",&x);
                enqueue(x);  
                break;  
            }  
            case 2:  
            {  
                dequeue();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:
            {
                peek();
                break;
            }
            case 5:   
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