# Merge Intervals

Like most interval problems, it helps if you sort them first based on the starting value and then based on the end value. You can either employ heap sort or the traditional python sort would work too. Note for Java you might need to provide a comparator for this question.

Once sorting it is trivial to solve if you decide to build the result array from scratch. In-place might be possible but creating a new array makes life easier (Probably more memory efficient too because mid-array pops can be `O(n)` time).

So while building the new array you have three cases:
1. Array is empty: Simply add the interval to the array.
2. Start of current interval is less than (or equal to) the end of the previous interval: In such a case, you want to adjust the end of the previous interval to be the max of the end of the previous interval, or the max of the end of the current interval
3. No overlap: Again, simply add the interval to the array.

The second case is the only involved step in the question really. No rocket science.
