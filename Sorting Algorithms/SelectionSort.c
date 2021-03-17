#include <stdio.h>
// Constant Space Algoritm
// Time Complexity : O(n^2)

void SelectionSort(int arr[], int);
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
    SelectionSort(A,n);
    printf("Sorted Array in ascending array: ");
    PrintArray(A,n);
}

void SelectionSort(int A[], int n)
{
    for(int i = 0;i < n-1; i++) //As only n-2 passes are enough
    {
        int iMin = i;
        for(int j = i+1; j < n; j++)
        {
            if(A[j] < A[iMin])
            {
                iMin = j;
            }
            int temp;
            temp = A[i];
            A[i] = A[iMin];
            A[iMin] = temp;
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