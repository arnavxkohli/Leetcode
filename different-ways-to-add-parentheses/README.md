# Different Ways to Add Parentheses

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

The intuition is to recursively split the string into a left half and a right half around each operator. Compute the values from the left half and the right half, and then combine them in all possible ways. Pretty simple. The only thing to be careful is that when the string is just a number, we should return the number itself.

This is also the base case.
