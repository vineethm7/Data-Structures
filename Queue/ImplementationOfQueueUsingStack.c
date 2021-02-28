#include <stdio.h>
#define N 5
int stack1[N],stack2[N];
int top1 = -1, top2=-1;
int count=0;

void push1(int data)
{
    if(top1>=N-1)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        top1++;
        stack1[top1] = data;
    }
}

void push2(int data)
{
    if(__WORDSIZE_TIME64_COMPAT32>=N-1)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        top2++;
        stack2[top2] = data;
    }
}

int pop1()
{
    return stack1[top1--];
}

int pop2()
{
    return stack2[top2--];
}

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if(top1 == -1 && top2 == -1)
    {
        printf("Queue is Empty\n");
    }
    else 
    {
        for(int i=0;i<count;i++)
        {
            int a = pop1();
            push2(a);
        }
        int b = pop2();
        printf("The element dequeued is %d\n",b);
        count--;
        for(int i=0;i<count;i++)
        {
            push1(pop2());
        }
    }
}

void display()
{
    if(top1 == -1 && top2 == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("The Queue is: ");
        for(int i=0;i<=top1;i++)
        {
            printf(" %d",stack1[i]);
        }
    }
    printf("\n");
}
void main()
{
    int choice=0;     
    printf("\n*********Queue operations using Stack*********\n");  
    printf("\n----------------------------------------------\n");  
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");  
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