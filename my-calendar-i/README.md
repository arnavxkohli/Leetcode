# My Calendar I

Need to look at the max of the start time (start time furthest to the left) and the min of the end time (end time furthest to the right) to see if there is a gap between the two times. If there is a gap, then we can insert the new event. If there is no gap, then we cannot insert the new event. Solved using sorted set, can probably be solved using a heap.

That is the noob way to do it. I will do it with a [segment tree](https://leetcode.com/problems/my-calendar-i/solutions/5752330/segment-trees-o-logn-complexity-bst-faster-than-99-sumbissions/?envType=daily-question&envId=2024-09-26).

The only thing really confusing me is why it works with the given inequalities. It really shouldn't but it does. Strange.

Actually I get it. The booking inside the calendar and the new booking are BOTH half range. This means we expect the same bounds on either end. This is the same as it being closed off on both ends but with the right half being one integer lower.

[15, 20), [18, 21) is the same as [15, 19] and [18, 20]. No real difference.
