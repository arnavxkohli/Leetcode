# My Calendar III

Interesting algorithm. Sweep line for maximum overlapping intervals during a period. Looks like half-open intervals are the norm in these time related cases. Hubspot had similar question tbh.

The [10, 20), [20, 30), [20, 40) edge case still works because the count will be 1 at 20 and active becomes 2. This comment is quite important to get the intuition.
