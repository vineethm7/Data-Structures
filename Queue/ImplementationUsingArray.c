#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == N-1)
    {
        printf("Queue is overflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else 
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is underflow\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else 
    {
        printf("The element dequeued is %d\n",queue[front]);
        front++;
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Element at front of queue is %d\n",queue[front]);
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("The Queue is: ");
        for(int i=front;i<=rear;i++)
        {
            printf(" %d",queue[i]);
        }
    }
    printf("\n");
}
void main()
{
    int choice=0;     
    printf("\n*********Queue operations using Array*********\n");  
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