# Longest Substring Without Duplicates

One of the classics, this is a sliding window question.

Highlighting only one solution here. The trick is to keep increasing the window until it is invalid (as in all sliding window questions). The window becomes invalid when the character at the end of it `s[r]` has been encountered before within the same window. To keep track of characters encountered within the same window a set can be used for `O(1)` lookup.
Keep incrementing the left end of the array until the right end is not in the set anymore. At each point, you want to add the right element to the array.
Remember that the `window_size` is traditionally `(r-l+1)`
