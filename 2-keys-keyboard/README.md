# 2 Keys Keyboard

This is a good dp and math problem (two things you struggle with here on leetcode). There are two main solutions which you have attempted.

The trick to this question is to realize that the answer = `min(num/factor + dp(factor))`, where the `num/factor` is the number of copy/pastes needed to get to `num` once you are at the factor, and the `dp(factor)` is the shortest path to the factor.

This is the dynamic programming approach, but you can be greedy and optimize the solution. The greedy solution involves noticing that:

`min(num/factor + dp(factor)) = num/largest_factor + dp(largest_factor)`.
