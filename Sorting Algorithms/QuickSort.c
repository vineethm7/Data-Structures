#include <stdio.h>
// Space Complexity : O(nlogn)
// Time Complexity : O(nlogn)

void QuickSort(int arr[], int, int);
int Partition(int arr[], int, int);
void PrintArray(int arr[], int);

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n;
    printf("Enter Number of Elements in Array:\n");
    scanf("%d",&n);
    int A[n];
    printf("Enter Elements in Array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Unsorted Array: ");
    PrintArray(A,n);
    QuickSort(A,0,n-1);
    printf("Sorted Array in ascending array: ");
    PrintArray(A,n);
}

int Partition(int A[], int l, int u)
{
    int pivot = A[u];
    int i = l-1;
    for (int j = l; j <u; j++) 
    {
        if (A[j] <= pivot) 
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[u]);
    return (i + 1);
}

void QuickSort(int A[], int l, int u)
{
    int p;
    if(l < u)
    {
        p = Partition(A,l,u);
        QuickSort(A,l,p-1);
        QuickSort(A,p+1,u);
    }
}

void PrintArray(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}