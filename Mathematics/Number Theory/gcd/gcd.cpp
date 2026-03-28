#include <iostream>
using namespace std;


long long recursive_gcd(long long a, long long b) {
    a = llabs(a); b = llabs(b);

    return (b == 0) ? a : recursive_gcd(b, a%b);
}


long long iterative_gcd(int a, int b) {
    a = llabs(a); b = llabs(b);

    while(b != 0) {
        long long r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main() {

    cout << recursive_gcd(6, 18) << endl;
    cout << iterative_gcd(6, 24) << endl;

}