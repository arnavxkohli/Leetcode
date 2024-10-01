# Check if array pairs are divisible by k

Simple number theory here, find the modulos, if there is a complement modulo in the array with the same number of elements, then continue, else return false. There are some edge cases:

- `i = 0`: For this case, just make sure that the number of elements is even.
- If k if even: Then the number of elements with modulo k/2 should be even.
- For negative modulo: Add k to get the complement.
