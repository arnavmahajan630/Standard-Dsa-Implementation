#include <iostream>
#include <vector>
using namespace std;

// Sqrt(N) check for primes
bool isprime(int n) {

    for(int i = 2; i*i <= n; ++i) {
        if(n%i == 0)return false;
    }
    return true;

}

int main() {
    int x;
    cin >> x;
    if(isprime(x))cout << "Is prime" << endl;
    else cout << "is not prime" << endl;

    return 0;
}