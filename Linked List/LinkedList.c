#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void insertAtBegin(node**,int);
void insertAtEnd(node**,int);
void insertAtAnyPos(node**,int,int);
void delete(node**,int);
int  listLength(node*);
void printList(node**);
void reverseList(node**);

int main()
{
    node *head;
    head=NULL;
    printf("Enter input to perform operation on Singly Linked List:\n");
    while(1)
    {
        int op;
        printf("1.Insert at start\n2.Insert at end\n3.Insert at some pos\n4.Delete at any pos\n5.Reverse the List\n6.Number of Nodes\n7.Print the List\n8.EXIT\n");
        scanf("%d",&op);
        if(op==1)
        {
            int data;
            printf("Enter element to insert be inserted at beginning:");
            scanf("%d",&data);
            insertAtBegin(&head,data);
        }    
        if(op==2)
        {
            int data;
            printf("Enter element to be inserted at end:");
            scanf("%d",&data);
            insertAtEnd(&head,data);
        }    
        if(op==3)
        {
            int pos,data;
            printf("Enter the position where u want to insert element: ");
            scanf("%d",&pos);
            printf("Enter element: ");
            scanf("%d",&data);
            if(pos==1)
            {
                insertAtBegin(&head,data);
            }
            else
            {
                insertAtAnyPos(&head,pos,data);
            }    
        }    
        if(op==4)
        {
            int pos;
            printf("Enter position of element you want to delete: ");
            scanf("%d",&pos);
            delete(&head,pos);
        }   
        if(op==5)
        {
            reverseList(&head);
        } 
        if(op==6)
        {
            int cnt = listLength(head);
            printf("Number of nodes in Linked List are: %d\n",cnt);
        }
        if(op==7)
        {
            printList(&head);
        }
        if(op==8)
        {
            printf("\nThank You\n");
            break;
        }
    }
}


void insertAtBegin(node **head,int data)
{
    node *newnode;
    newnode = (node*)malloc(sizeof( node));
    newnode->data = data;
    if(*head==NULL)
    {
        newnode->next = NULL;
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        *head = newnode;
    }    
}


void insertAtEnd(node **head, int data)
{
    node *newnode,*temp;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(*head==NULL)
    {
        newnode->next = NULL;
        *head = newnode;
    }
    else 
    {
        newnode->next = NULL;
        temp = *head;
        while(temp->next!=0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }   
}

void insertAtAnyPos(node **head,int pos,int data)
{
    int i=1,cnt;
    node *newnode,*temp;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    temp = *head;
    cnt = listLength(temp);
    if(pos>cnt || pos<=0)
    {
        printf("\nInvalid Position\n");
    }
    else
    {
        temp = *head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void delete(node **head,int pos)
{
    node *currrent = *head;
    node *previous = *head;
    if(*head == NULL)
    {
        printf("\nList is Empty!\n\n");
    }
    else if(pos == 1)
    {
        *head = currrent->next;
        free(currrent);
        currrent = NULL;
    }
    else
    {
        while(pos != 1)
        {
            previous = currrent;
            currrent = currrent->next;
            pos--;
        }
        previous->next = currrent->next;
        free(currrent);
        currrent = NULL;
    }
    
}

void reverseList(node **temp)
{
    node *prev,*curr,*next;
    prev = NULL;
    curr = *temp;
    next = *temp;
    while( next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *temp = prev;
}

int listLength(node* head)
{
    int count=0;
    node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
} 


void printList(node** n)
{
    node *temp;
    temp = *n;
    printf("The List is: \n");
    while (temp != NULL) 
    { 
        printf(" %d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n");
}
