## Notes on Topics Related to Number Theory

### Greatest Common Divisor

* Gcd(a, 0) = a
* if a divides be then gcd(a, b) = a. fair enough. also (-) dosent matter

Steps of Euclid
* a = d * n and b = d * m
* a - b = d *(n - m)
* thus gcd(a, b) = gcd(a-b, b)
* gcd(a-kb, b) => a >= b. a-kb = r = a%b. 
* gcd(a, b) = gcd(r, b) = gcd(b, a%b). recursive derivation

* TC O(log(min(a,b))) slowest for consecutive fib numbers

#### Properties

* gcd(a,b) is a building block for ax + by 
* every common divisor of a,b is a divisor of gcd(a,b)
* gcd(a,b) is the smallest positive integer that can be written as ax + by. All multiples of a*x + b * y are multiples of gcd(a,b).
* gcd(m*a, m*b) = m*gcd(a, b) => gcd(a,b) = g THEN: gcd(a/g, b/g) = 1;

* ##### After dividing numbers by their gcd they become co-prime

* gcd(a + mb, b) = gcd(a, b) // Since ofcourse this is the recurrence relation of gcd reduction.
* gcd(a, b) = gcd(b, a%b) the main identity. logarithmic time


### Least Commin Multiple

* lcm(a, b) = a*b/gcd(a,b)

#### Properties

* 
