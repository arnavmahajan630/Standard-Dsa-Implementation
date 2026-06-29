## GCD and LCM Introduction and Properties

* gcd(a,0) = a
* gcd(1, a) = 1
* gcd(a,b) = gcd(|a|, |b|)
* IF a divides b then gcd(a, b) = |a|

### Recursive relation of GCD
* gcd(a,b) = gcd(a-b, b) where a >= b => gcd(a-qb, b) => gcd(a,b) = gcd(b, a%b)
*TC O(log(min(a,b)))

### LCM
*  a/gcd(a,b)* b = LCM

### Properties of GCD

* for a,b gcd(a,b) is a number such that ax + by is a multiple of gcd(a,b)
* Every `Common divisor` of a,b is a divisor of gcd(a,b)
* gcd(a,b) is the smallest positive integer that can be written as ax + by
* gcd(ma, mb) = m*gcd(a,b)
* gcd(a,b) = g then gcd(a/g, b/g) = 1
* gcd(a, lcm(b,c)) = lcm(gcd(a,b) , gcd(a,c))
* gcd(a,b) + 1 is the number of integrer points on a line drawn from (0,0) to (a,b)
* gcd of an AP = gcd(a,d)
* gcd(n!,m!) = min(n,m)!
* gcd(a^x, a^y) = a^min(a,y)

* lcm(a,b) * gcd(a,b) = a * b
* 