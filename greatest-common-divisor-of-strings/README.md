# Greatest Common Divisor of Strings

There are two ways to do this: One is the stupid way, trying out every combination of the smaller string, which works. The smarter way is using Euclid's algorithm to find the gcd and returning that from the smaller string. The only way that this would return a possible answer is if `s1 + s2 == s2 + s1`.
