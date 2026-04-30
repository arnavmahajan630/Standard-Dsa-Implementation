## Two main ways to appraoch DP

* Tabulation  (bottom up approach)
* Memoization (top down approach)


### Memoization
* Store the vlaues of previously computed subproblems and store them in a N-dimentional array based on the n parameters our recursive function depends on and use them as required when faced with an overlapping subproblem

1. Declare Dp array
2. Handle the base cases for the array
3. Define the base cases for recursive function
4. return the dp value if valid
5. call for the recursive case to compute the dp value for future

