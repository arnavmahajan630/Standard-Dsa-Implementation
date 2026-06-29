## Divisors and It's Properties

* a is a divisor of b when a%b == 0 i.e a | b

* Calculating divisors:
    - SQRT
     - for a number x it is gaurenteed that all half pair lie <= sqrt(x)
     - if a | n => n/a | n thus ceating pairs of divisors
    - Good for 1e12

* Number of factor t(n)
     -  Represet a number in it's prime factor form p^a, p2^a2 ...
     - t(n) = (a + 1) * (a2 + 1) ... (ak + 1) gives the number of factors of a number

* Sum of factors sig(n)
     - for every prime p that represnts the number the number write down it's powered version
     - 72 = 2^3*3^2 thus (2^0 + 2^1 + 2^2 + 2^3)(3^0 + 3^1 + 3^2) = Sum of divisors of 72
    - This appears to be GP thus (a^n-1/ n-1)

* Product of all Factors u(n)
    - n^(t(n)/2) => number of pairs * N where pairs is number of factors / 2

* Precomputing Factors (Sieve Style)
    - `divisors[j].push_back(i)` for a `vector<vector<int>>` like sieve marks it's multiples as not prime the prime is saved as a divisor ofr all those numbers
