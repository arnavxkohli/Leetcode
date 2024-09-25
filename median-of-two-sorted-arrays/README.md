# Median of two sorted arrays

You know you need two halves of the array. Partition into two halves with binary search on the smaller array. Once you know the amount of elements in the smaller array's partition, you can find the equivalent for the larger array. The "check" step is ensuring the right most element of both arrays' partitions are smaller than the next element in the OTHER array.

Look at [NeetCode](https://www.youtube.com/watch?v=q6IEA26hvXc)'s video for more details.
