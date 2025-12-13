#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int recursive(int a, int b) {
    if(b == 0)return 1;
    long long res = recursive(a, b/2);

    if(b&1)return (a * ((res * 1LL * res)%M))%M;
    else return res * res;
}

int iterative(int a, int b) {
    
}


int main() {

   cout << recursive(2, 3) << endl;
    return 0;
}