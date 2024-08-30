# Continuous Subarray Sum

To solve this question, you need to maintain a prefix "sum" which is more like the prefix modulo. If you encounter a modulo you have seen before, you just need to verify that the difference is > 1.

The logic of storing it into a hash map is similar to subarray sum equals k and maximum subarray sum equals k. Similar kinds of questions.
