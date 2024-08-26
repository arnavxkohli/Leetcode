# Interleaving String

The key idea here is to check if s1[:i] and s2[:j] can form s3[:i+j-1]

# 2D DP

- First Row and First Column Initialization: The code initializes the first row and column of the DP table to handle cases where only one string (s1 or s2) contributes to the interleaving at the start.
- Filling the DP Table: While filling the DP table, the code considers every possible position in s3 where characters from both s1 and s2 might be interleaved. The logic ensures that at each step, either a character from s1 or s2 can match the corresponding character in s3.
- Balanced Interleaving: The dynamic programming approach ensures that the interleaving is balanced. As it processes s1 and s2 character by character, it prevents one string from being overly dominant in the interleaving process.

The main observation for the 1D DP optimization is that we only need the previous row in the dp matrix.

We set every value to True initially, so that there is no conflict in case there is an undeterminate state.
