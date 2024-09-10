# Insert Greatest Common Divisors In Linked List

This is a classic fast and slow pointer question, the only real trick here is that you need to keep track of the gcd. To do this, you can either use the standard library function for it or use Euclid's Algorithm:

## Algorithm Principle

For two positive integers `a` and `b` the GCD of `a` and `b` is the same as the GCD of `b` and `a%b`.

## Algorithm Steps

- Initialize: Start with two integers `a` and `b`.
- While Loop:

  - Compute the remainder `r` of dividing `a` and `b`.
  - Replace `a` with `b` and `b` with `r`.
  - Continue till `b` becomes zero.

- Result: When `b` is zero, `a` is the GCD.
