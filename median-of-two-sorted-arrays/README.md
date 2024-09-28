# Median of two sorted arrays

You know you need two halves of the array. Partition into two halves with binary search on the smaller array. Once you know the amount of elements in the smaller array's partition, you can find the equivalent for the larger array. The "check" step is ensuring the right most element of both arrays' partitions are smaller than the next element in the OTHER array.

Look at [NeetCode](https://www.youtube.com/watch?v=q6IEA26hvXc)'s video for more details.

This is quite a tricky question to solve even after the hints. You need to realize that you will have the end of the left partition and the beginning of the right partition for both arrays. Your midpoint needs to target the start of the right partition for the smaller of the two, and then figure out the correct logic between l1, l2, r1, r2. That makes it work. Some nuanced tricks here and there. Overall this is one of the hardest top interview 150 questions I have come across.
