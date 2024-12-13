# Trapping Rain Water

If `l_max` is less than `r_max`, it implies that the left side is limiting the amount of water that can be trapped. Therefore, you can safely move the left pointer to the right (`l += 1`), as any trapped water will depend on `l_max`.
If `r_max` is less than or equal to `l_max`, move the right pointer to the left (r -= 1) for the same reason.

Water cannot rise above the shorter barrier without spilling over. Therefore, the maximum height of water that can be trapped above a bar is determined by the lower of the two walls.
