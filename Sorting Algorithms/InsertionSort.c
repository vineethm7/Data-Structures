#include <stdio.h>
// Constant Space Algoritm
// Time Complexity : O(n^2)

void InsertionSort(int arr[], int);
void PrintArray(int arr[], int);

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
    InsertionSort(A,n);
    printf("Sorted Array in ascending array: ");
    PrintArray(A,n);
}

void InsertionSort(int A[], int n)
{
    for(int i = 1;i < n; i++) 
    {
        int value = A[i];
        int hole = i;
        while(hole > 0 && A[hole-1] > value)
        {
            A[hole] = A[hole-1];
            hole = hole-1;
        }
        A[hole] = value;
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