# Car Fleet

The key insight here is that the time to reach the destination array must be a monotonically increasing stack. First we need to ensure we have the array sorted. This is because, if a car reaches the destination before the highest time present on the stack, then it will be a part of one of the previous fleets, so it does not need to be considered.

Watch [NeetCode's explanation](https://www.youtube.com/watch?v=Pr6T-3yB9RM) of this problem.
