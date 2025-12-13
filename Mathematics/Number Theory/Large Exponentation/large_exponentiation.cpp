#include <bits/stdc++.h>
using namespace std;

// for  a>=1e9 + 7
// take => a %=M since (a%M)^b = (a^b)%M


// if M >= 1e9 + 7
// we get a overflow error for a * a since we allow storage of 1e18 which is overflow during their multiplication
// use binary multiplication


// we multiply a*a as a + a + a... a times taking module in each step +a
// this results in a complexity of O(a) log(a) is needed

//  we use the same concept as bin exp but instead add the set bits

const long long M = 1e18 + 7;

int binaryMulti(int a, int b) {
    int ans = 0;
    while(b > 0) {
        if(b&1)ans = (ans+a)%M;
        a = (a + a)%M;
        b>>=1;
    }
    return ans;
}

int LargeExpModGreater(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b&1)ans = binaryMulti(ans, a);
    }
    a = binaryMulti(a, a); 
    b >>=1; 
}

// TC = log^2(N)
int main() {

    return 0;   
}