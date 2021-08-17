#include <iostream>

using namespace std;

int BinarySearch(int A[], int low, int high, int x)
{ 
    if(low > high) return -1;
    int mid = low + (high-low)/2; //(low+high)/2
    if(x == A[mid]) return mid; //Found X, return (exit)
    else if(x < A[mid]) return BinarySearch(A,low,mid-1,x); //X lies before mid
    else return BinarySearch(A,mid+1,high,x); //X lies after mid
    return -1;
}

int main()
{
    int A[] = {2, 4, 5, 7, 13, 14, 15, 23};
    cout << "Enter a number";
    int x;
    cin >> x;
    int low = 0, high = 7;//n-1
    int index = BinarySearch(A,low,high,x);
    if(index!=-1) cout << "Number " << x << " is at index " << index << endl;
    else cout << "Number " << x << "not found" << endl;
}