#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;

node* newnode(int data)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insert(node *root,int data)
{
    if(root==NULL)
    {
        return newnode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right,data);
    }
    return root;
}

node* search(node* root, int data)
{
	if (root == NULL || root->data == data)
	{
        return root;
    }
	else if (root->data < data)
    {
        return search(root->right,data);
    }
    else
    {
        return search(root->left, data);
    }    
}

node* FindMin(node* root)
{
   if(root == NULL)
   {
       return NULL;
   }
   else if (root->left != NULL)
   {
       return FindMin(root->left);
   }
   return root;
}

node* delete(node *root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else if(data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else
    {
        //Case 1: No Child
        if(root->left==NULL && root->left==NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: 2 Children
        else
        {
            node *temp;
            temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}


void inOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    node *root = newnode(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);
    inOrder(root);
    printf("\n");
    delete(root,1);
    inOrder(root);
    printf("\n");
    delete(root,15);
    inOrder(root);
    printf("\n");
}