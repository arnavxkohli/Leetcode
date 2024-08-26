# Longest Increasing Subsequence

Basically, can solve this recursively with dp from the beginning or the end. For the LIS found till index i+1, index i can contribute to it if nums[i] is less than nums[i+1] (this will elongate the sequence). No real tricks to this. Probably watch a video for the [binary search](https://www.youtube.com/watch?v=on2hvxBXJH4) solution.
