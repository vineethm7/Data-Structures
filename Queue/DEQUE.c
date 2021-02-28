#include <stdio.h>
#define N 5
int deque[N];
int front = -1;
int rear = -1;

void enqueuefront(int x)
{
    if((front==rear+1) || (front==0 && rear==N-1))
    {
        printf("Deque is overflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if(front==0)
    {
        front = N-1;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}

void enqueuerear(int x)
{
    if((front==rear+1) || (front==0 && rear==N-1))
    {
        printf("Deque is overflow\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if(rear==N-1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else 
    {
        rear++;
        deque[rear] = x;
    }
}

void dequeuefront()
{
    if(front==-1 && rear==-1)
    {
        printf("Deque is Empty\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==N-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
}

void dequeuerear()
{
    if(front==-1 && rear==-1)
    {
        printf("Deque is Empty\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=N-1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\nDeque is Empty\n");
    }
    else
    {
        int i = front;
        printf("The Deque is: ");
        while(i != rear)
        {
            printf("%d ",deque[i]);
            i = (i+1)%N;
        }
        printf("%d",deque[rear]);
    }
    printf("\n");
}
int main()
{
    int choice=0;     
    printf("\n*********Double Ended Queue operations*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 6)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.enqueuefront\n2.enqueuerear\n3.dequeuefront\n4.dequeuerear\n5.Display\n6.EXIT");  
        printf("\nEnter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                int x;
                printf("Enter the element to be enqueued at front: \n");
                scanf("%d",&x);
                enqueuefront(x);  
                break;  
            }  
            case 2:  
            {  
                int x;
                printf("Enter the element to be enqueued at rear: \n");
                scanf("%d",&x);
                enqueuerear(x);  
                break;  
            }  
            case 3:  
            {  
                dequeuefront();  
                break;  
            }  
            case 4:
            {
                dequeuerear();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:   
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