#include <iostream>

using namespace std;

long pow(int x, int n) {
    if (n==0)
        return 1;
    else if (n%2==0)
    {
        int y = pow(x,n/2);
        return y*y;
    }    
    else 
        return x*pow(x,n-1);   

}

int main() {
    int x,n;
    cout << "Enter Base: " << endl;
    cin >> x;
    cout << "Enter Exponent: ";
    cin >> n;
    long l = pow(x, n);
    cout << l << endl;
    return 0;
}