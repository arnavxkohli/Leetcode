# Successful pairs of spells and potions

The only really tricky bit is the r = mid condition. Have seen this kind of thing a lot tbh. It's a binary search, but the condition is a bit different. Remember to cast to long long if doing it in cpp.

So this is called a lower bound binary search. The other kind is called an upper bound binary search where you use > instead of >=. In both cases you don't exclude mid from the search space.

Summary of Types of Binary Search:

- Standard Binary Search: Exact match (arr[mid] == target).
- Lower Bound: First element meeting a condition (arr[mid] >= target).
- Upper Bound: First element strictly greater than target (arr[mid] > target).
- Binary Search on Continuous Values: Search with precision threshold.
