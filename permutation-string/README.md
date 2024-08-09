# Permutation String

This is a sliding window problem. As usual, we need to keep track of a valid window and work the problem around the conditions when we have one.

For some context, `s1_freq` is the frequency of the first string, `s2_freq` is the frequency of the second string.

Before explaining further, some terminology:
1. Pseudo Invalid State: In this state, we encounter a character on the right end (`curr_char`) which is in the frequency map for `s1`, but after adding it to `s2`'s frequency map, it goes over `s1_freq[curr_char]`.
2. Pseudo Valid State: In this state, the frequencies of elements are all either equal to or less than their corresponding frequencies in `s1_freq`, but all of the keys of `s1_freq` have not been encountered yet.

In this particular question, it is more useful to try to find the *invalid window*. There are two conditions where this can happen:
1. In the first condition, a window can be considered invalid (Pseudo invalid from above) if on adding `s2[r]` (the character at the right end of the window), the frequency of the element in the `s2` frequency map goes higher than the corresponding frequency of the same character, `s2[r]` in the `s1` frequency map (where `s1` is the target, mind you). Since we always have a valid map after all is said and done, we can just compare our current `s2_freq` with `s1_freq`
2. The second condition is easier. It occurs when we encounter an element that is not in the `s1` frequency map. We don't want to waste time with checking this character and can thus skip over it completely.

In the first case, the left end of the window, `l` is incremented until we reach the point where the frequency of the current character `s2[r]` is the same in both `s1_freq` and `s2_freq`

In the second case, the skip over logic involves moving `l` to `r+1`. We can also reset the `s2_freq` to empty. This is so that no part of the window can potentially be "left behind" on a character which is not a part of `s1_freq`.
