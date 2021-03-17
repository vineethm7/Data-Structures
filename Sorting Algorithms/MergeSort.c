#include <stdio.h>
// Space Complexity: O(n)
// Time Complexity : O(nlogn)

void MergeSort(int arr[], int, int);
void Merge(int arr[], int, int, int);
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
    MergeSort(A,0,n-1);
    printf("Sorted Array in ascending array: ");
    PrintArray(A,n);
}

void Merge(int A[],int l, int mid, int r)
{
    int temp[50];	//array used for merging
	int i,j,k;
	i=l;	//beginning of the first list
	j=mid+1;	//beginning of the second list
	k=0;
	
	while(i<=mid && j<=r)	//while elements in both lists
	{
		if(A[i]<A[j])
			temp[k++]=A[i++];
		else
			temp[k++]=A[j++];
	}
	
	while(i<=mid)	//copy remaining elements of the first list
		temp[k++]=A[i++];
		
	while(j<=r)	//copy remaining elements of the second list
		temp[k++]=A[j++];
		
	//Transfer elements from temp[] back to a[]
	for(i=l,j=0;i<=r;i++,j++)
		A[i]=temp[j];
}

void MergeSort(int A[], int l, int r)
{
    int mid = (l+r)/2;
    if(l < r)
    {
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,r);
        Merge(A,l,mid,r);
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