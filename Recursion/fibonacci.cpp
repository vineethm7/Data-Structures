//Recursion may not be best always.Check other file for good recursion solution

/*
#include <iostream>

using namespace std;

int Fibonacci(int n) {
    if (n==0 or n==1) 
        return n;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
   int n;
    cout << "Enter number: ";
    cin >> n;
    int l = Fibonacci(n);
    cout << l << endl;
    return 0; 
}
*/

//Iterative Approach of Same

#include <iostream>

using namespace std;

int Fibonacci(int n) {
    if(n<=1) 
        return n;
    int F1,F2,F;
    F1=0;
    F2=1;
    for(int i=2; i<=n;i++) {
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;    
}

int main() {
   int n;
    cout << "Enter number: ";
    cin >> n;
    int l = Fibonacci(n);
    cout << l << endl;
    return 0; 
}