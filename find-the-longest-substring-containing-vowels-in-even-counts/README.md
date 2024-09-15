# Find the Longest Substring Containing Vowels in Even Counts

This question is actually a lot easier once you use the bitmask. It is similar to the maximum subarray with sum equals k. You can toggle the parity of the vowel with the specific bits assigned to them. If you see a parity seen before, that means between the two parities, you have a valid solution. Just find the maximum of this window.
