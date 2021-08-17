#include <iostream>

using namespace std;

long factorial(int n) {
    if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    long l = factorial(n);
    cout << "Factorial is " << l << endl;
    return 0;
}