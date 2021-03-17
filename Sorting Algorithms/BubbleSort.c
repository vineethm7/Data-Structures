#include <stdio.h>
// Constant Space Algoritm
// Time Complexity : O(n^2)

void BubbleSort(int arr[], int);
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
    BubbleSort(A,n);
    printf("Sorted Array in ascending array: ");
    PrintArray(A,n);
}

void BubbleSort(int A[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(int j = 0; j<n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
           break;
        }
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