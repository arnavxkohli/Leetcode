# Find Peak Element

- The algorithm initializes two pointers, l (left) and r (right), to represent the current search bounds.
- It calculates the middle index mid as the average of l and r.
- It checks if the element to the right of mid (i.e., nums[mid + 1]) is greater than nums[mid]:
  - If true, it means there is a potential peak in the right half of the array, so we move the left pointer to mid + 1 (l = mid + 1).
  - If false, it indicates that mid is either a peak or there is a peak in the left half of the array, so we set r = mid.
By setting r = mid, we effectively narrow down the search space while still including mid as a candidate for a peak. This allows the algorithm to continue checking in the left half, where it might find a peak element, without skipping over mid (which could potentially be a peak). This adjustment ensures that the search converges correctly and eventually finds a peak element, as at least one peak is guaranteed to exist in the array.
