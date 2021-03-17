#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;
int top = -1;
node *S[20];
node* create()
{
    int x;
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter data (-1 for No node):");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0 ;
    }
    newnode->data = x;
    printf("\nLeft Child of %d is ",x);
    newnode->left = create();
    printf("\nRight Child of %d is ",x);
    newnode->right = create();
    return newnode;
}

void InOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

void PreOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->data);
    }
}

void IterInOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    node *temp = root;
    while(temp!=NULL)
    {
        S[++top] = temp;
        temp = temp->left;
    }
    temp = S[top--];
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        if(temp->right !=NULL)
        {
            temp = temp->right;
            while(temp!=NULL)
            {
                S[++top] = temp;
                temp = temp->left;
            }
        }
        temp = S[top--];
    }
}

void IterPreOrder(node *root)
{
    node *temp = root;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        if(temp->right!=NULL)
        {
            top++;
            S[top] = temp->right;
        }
        if(temp->left != NULL)
        {
            temp = temp->left;
        }
        else
        temp = S[top--];
    }
}

int main()
{
    node *root = NULL;
    root = create();
    printf("\nInOrder Traversal is: ");
    InOrder(root);
    printf("\nPreOrder Traversal is: ");
    PreOrder(root);
    printf("\nPostOrder Traversal is: ");
    PostOrder(root);
    printf("\nInOrder Traversal without using recursion is: ");
    IterInOrder(root);
    printf("\nPreOrder Traversal without using recursion is: ");
    IterPreOrder(root);
}