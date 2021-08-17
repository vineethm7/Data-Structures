//Recurion with Memoization
#include <iostream>

using namespace std;

int F[51];
int Fibonacci(int n) {
    if(F[n] != -1) {
        return F[n];
    }
    F[n] = Fibonacci(n-1) + Fibonacci(n-2);
    return F[n];
}

int main() {
    for(int i=0;i<51;i++) 
    {
        F[i] = -1;
    }
    F[0] = 0;
    F[1] = 1;
    int n;
    cout << "Enter number: ";
    cin >> n;
    int l = Fibonacci(n);
    cout << l << endl;
    return 0; 
}