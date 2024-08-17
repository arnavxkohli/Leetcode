# Insert Interval

Similar to most interval based problems, you can reconstruct the result array from the sorted list of intervals. In this case, you need to check the bounds of the interval being inserted. If the current interval lies outside the bounds of the new interval (the interval being inserted), then the interval can be inserted as normal

The only time this changes is when the new interval's start or end lies between the current intervals. There are two cases:
1. `new_start` lies between the current start and end: Adjust the `new_start` to be the minimum of the `cur_start` and the `new_start`.
2. `cur_start` lies between the new start and end: Adjust the `new_end` to be the maximum of the `cur_end` and the `new_end`.

After the adjustments, the updated interval bounds can be added as an interval to the array
