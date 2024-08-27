# Subarray Sum Equals K

This question is similar to maximum size subarray sum equals k. The only difference here is for each prefix sum (running sum), we have to store all possible indices corresponding to it. If we encounter a running sum such that running sum - target has already been encountered, we can add all the indices corresponding to that running sum. The reason is that the difference in the prefix sums for any two indices is the sum between those two indices.
