# Find Minimum In Rotated Sorted Array

This is a binary search question. We are concerned with narrowing the search range until we hit the right element (which will be the minimum). There are three cases:
1. The minimum is in the middle of our search range
2. The minimum is towards the right of our search range: This occurs when the left side is monotonically increasing, but the right side isn't. Due to the properties of a rotated sorted array it is sufficient to check that the right side is not monotonically increasing.
3. Similar to above but the minimum is towards the left. If the right side is monotonically increasing starting from mid, then there is no point exploring the right side because we will only find larger values.

2 and 3 can be checked by comparing `nums[mid]` with `nums[l]` and `nums[r]` as the two ends of the search range.

A few test cases are shown below which illustrate this:

``` bash
[1, 2, 3, 4, 5, 6, 7, 8]
[8, 1, 2, 3, 4, 5, 6, 7]
[7, 8, 1, 2, 3, 4, 5, 6]
[6, 7, 8, 1, 2, 3, 4, 5]
[5, 6, 7, 8, 1, 2, 3, 4]
[4, 5, 6, 7, 8, 1, 2, 3]
[3, 4, 5, 6, 7, 8, 1, 2]
[2, 3, 4, 5, 6, 7, 8, 1]
```
