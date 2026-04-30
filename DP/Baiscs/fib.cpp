#include <iostream>
#include <vector>
using namespace std;

vector<long long>v(1e3 + 4, -1);

long long fib(long long n) {
    if(n <= 1)return n;
    return (v[n] != -1) ? v[n] :  v[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    cout << "Enter the number to find fibbonanni for: ";
    int n;
    cin >> n;
    cout << "\nThe " << n << "th fib number is: ";
    cout << fib(n);
}