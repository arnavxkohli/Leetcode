# Maximum Length of Repeated Subarray

This is a classic tabulation dp problem. Create a 2D table with the rows corresponding to the indices of the first array and the columns corresponding to those of the second array. The index of the row or column refers to the maximum length of the repeated subarray ending at that point. So we need m+1 and n+1 rows/columns respectively.

This is similar to the longest common substring problem which was detailed in the dynamic programming course in year 2. He had a lecture about it following the tabulation approach too.
