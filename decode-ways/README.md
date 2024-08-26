# Decode Ways

This is the worst question known to mankind. Classic Fibonacci type dynamic programming problem with a constraint that you need to be able to decode the whole string completely. This adds a slight twist which was tricky to resolve.
1. Base Case: For an empty string, there is 1 way to decode it. For the first letter, if it is 0, there are no ways to decode it, if it isn't 0, then there is 1 way to decode it
2. For each subsequent index, if the current index is not 0, then we can continue with the streak from the previous index's value in the table. If it is 0 then do nothing for the previous index
3. If the current and previous values combined yield an integer in the range 10 and 26 then we can add the sequence from two indices ago.

These are the main decision points. Nothing too tricky if visualized like this tbh. Bottom up is easier to visualize because of the valid case constraint.
