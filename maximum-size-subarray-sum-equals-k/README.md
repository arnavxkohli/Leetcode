# Maximum size subarray sum equals k

This question involves storing the prefix sums (but also including the last index in them). For every sum, we can check if a previous index had a prefix sum which subtracted from it produces the target. This allows us to solve the question in one pass, by starting from the previous index and coming to the current index.
