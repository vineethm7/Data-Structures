#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

void insertAtBegin(node **,int);
void insertAtEnd(node **,int);
void insertAtAnyPos(node**,int,int);
int  listLength(node*);
void delete(node**,int);
void printList(node*);
void reverseList(node**);

int main()
{
   node *head; 
   head = NULL;
   printf("Enter input to perform operation on Doubly Linked List:\n");
   while(1)
   {
       int op;
       printf("1.Insert at start\n2.Insert at end\n3.Insert at some pos\n4.Delete at any pos\n5.Reverse the List\n6.Number Of Nodes\n7.Print The List\n8.EXIT\nEnter input to perform operation\n");
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
           int pos,data,count=0;
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
           int c= listLength(head);
           printf("No of Nodes in Linked List are: %d\n",c);
       }
       if(op==7)
       {
            printList(head);
       }
       if(op==8)
       {
           break;
       }
   }
}


void insertAtBegin(node **head, int data)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node*));
    newnode->data = data;
    if(*head==NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        *head = newnode;
    }
    else
    {
        newnode->prev = NULL;
        (*head)->prev = newnode;
        newnode->next = *head;
        *head = newnode;
    }
}

void insertAtEnd(node **head,int data)
{
    node *newnode,*temp;
    newnode = (node*)malloc(sizeof(node*));
    newnode->data = data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        newnode->prev = NULL;
        newnode->next = NULL;
        *head = newnode;
    }
    else
    {
        temp =*head;
        while(temp->next!= NULL)
        {
            temp = temp->next;
        }
        temp->next=newnode;
        newnode->prev = *head;
    }
}

void insertAtAnyPos(node **head, int pos, int data)
{
    node *newnode,*temp;
    temp = *head;
    newnode = (node*)malloc(sizeof(node*));
    newnode->data = data;
    int cnt;
    cnt = listLength(temp);
    if(pos>cnt || pos<=0)
    {
        printf("\nInvalid Position\n");
    } 
    else
    {
        int i=1;
        temp = *head;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }   
}

void delete(node **head,int pos)
{
    node *temp;
    temp = *head;
    int cnt = listLength(temp);
    if(*head==NULL)
    {
        printf("List is Empty\n");
    }
    else if(pos==1)
    {
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
    else if(pos==cnt)
    {
        int i=1;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=NULL;
        free(temp);
    }
    else
    {
        int i=1 ;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void printList(node* n)
{
    node *temp;
    temp = n;
    printf("The List is: \n");
    while (temp != NULL) 
    { 
        printf(" %d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n");
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

void reverseList(node **head)
{
    node *current,*nextnode,*tail;
    tail = *head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    if(*head==NULL)
    {
        printf("List is Empty\n");
    }
    current = *head;
    while(current != NULL)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    *head = tail;
}