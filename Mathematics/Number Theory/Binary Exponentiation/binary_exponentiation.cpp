#include <bits/stdc++.h>
using namespace std;

// Binary EXP with Modulo
const int M = 1e9 + 7;

int recursive(int a, int b) {
    if(b == 0)return 1;
    long long res = recursive(a, b/2);

    if(b&1)return (a * ((res * 1LL * res)%M))%M;
    else return res * res;
}

int iterative(int a, int b) {
    int ans = 1;
    while(b > 0) { // if unit bit is set multiply with base
        if(b&1)ans  = (ans * 1LL * a)%M;
        a = (a*a * 1LL )%M;
        b >>=1;
    }
    return ans;
}


int main() {

   cout << recursive(2, 3) << endl;
   cout << iterative(2, 3) << endl;
    return 0;
}