# Kth smallest in lexicographical order

The trick behind this question is the same as the other numeric lexicographic one. When you can get away with multiplying by 10, you should. The problem here is that the test cases can go up to 1e9. Which means, we need a logarithmic solution.

The solution is to basically count the number of possible numbers between say 1 and 2. If we need to find k = 6 and n = 13, we would then have [1, 10, 11, 12, 13, 2....]. Between 1 and 2 we have 5 numbers including 1. We can then increment the result by 1. We can alternatively multiply by 10, for example if we are finding k = 3 for n = 13.

We would then have the count between 1 and 2 is 5, so we have to multiply by 10.
