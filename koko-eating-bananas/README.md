# Koko Eating Bananas

Whenever we are given a search range, and a condition regarding narrowing the search range (to find a value) the first idea should be binary search. In this case, we are doing a modified binary search with some weird conditions.
One key observation is that we need at least as many hours as there are piles. Also, the lowest amount of bananas we can eat in one hour is 1.
This defines the range of our binary search as `l = 1` and `r = max(piles)`.

1. At each iteration we check the midpoint as the eating rate. If the eating rate finishes the bananas in less than or equal to the desired amount, we can move the max value (`r`) to below the midpoint. Each time we do this, it is important to record the last time this condition is valid.
2. For the reverse, in case the eating rate is too slow, we need to bring the min value (`l`) to above the midpoint.
3. The eating rate result needs to be initially set to be `r`, in case the hours are equal to the size of the array.
