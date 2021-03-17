#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void MAX_HEAPIFY(int*, int, int);
int * BUILD_MAX_HEAP(int*, int);
void swap( int*, int*);
int main()
{
	int heap_size;
	int *A = calloc(MAX,sizeof(int));
	printf("Enter no of elements in the array:\n");
	scanf("%d",&heap_size);
	printf("Enter the array\n");
    for (int i = 1; i <=heap_size; i++) 
	{
        scanf("%d", &A[i]);
    }
	BUILD_MAX_HEAP(A,heap_size);
	printf("The heap is:\n");
	for(int i=1; i<=heap_size;i++)
	{
		printf("%d\n",A[i]);
	}
	return 0;
}

int* BUILD_MAX_HEAP(int A[], int heap_size)
{
	for(int i = heap_size/2; i>=1; i--)
	{
		MAX_HEAPIFY(A,i,heap_size);
	}
}

void swap( int *a, int *b ) 
{
	int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MAX_HEAPIFY(int A[], int i, int heap_size)
{
    int largest, left, right;
    left = 2*i;
    right = 2*i+1;
	largest = i;
    if (left <= heap_size)
	{
        if(A[left]>A[largest])
		{
			largest = left;
		}
	}
	if(right <= heap_size)
	{
		if(A[right]>A[largest])
		{
			largest = right;
		}
	}
	if(largest!=i)
	{
		swap(&A[i],&A[largest]);
	    MAX_HEAPIFY(A,largest,heap_size);
	}	
}