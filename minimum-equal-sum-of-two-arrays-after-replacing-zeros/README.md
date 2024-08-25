# Minimum Equal Sum of Two Arrays After Replacing Zeros

There are two cases with impossibilities:
1. If the two arrays have different sums after accounting for zeros being replaced by 1 (the minimum number apart from 0), and the smaller array has no 0s, there is no contribution to increasing its sum and thus making it equal to the bigger array.
2. If the smaller array has too many zeros, then they at least need to be 1s and this could exceed the difference that needs to be covered.

It is sufficient to return -1 for these two cases and prove by contradiction that all other test cases should work fine. Another niche consideration is that it is insufficient to take the greater and lesser arrays based on the initial sums. The greater and lesser arrays should be decided after replacing all the zeros with 1s (since these have to be replaced anyway).

The following test case shows a condition where considering only the inital sum would fail. We need to consider the minimum maximum potential sum after replacing 0s with 1s in both arrays.

``` python
[8,13,15,18,0,18,0,0,5,20,12,27,3,14,22,0], [8,13,15,18,0,18,0,0,5,20,12,27,3,14,22,0]
```

Apart from this, no real demons in the question.
