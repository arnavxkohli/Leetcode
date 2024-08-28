# Find All Anagrams in a String

This is a pattern I have seen before. In a sliding window if you want to compare one frequency map against another, it is best to keep a have or need variable which reduced the lookup cost down to O(1) instead of comparing all elements within a hashmap.

The have and need concept can be seen in [Leetcode #76 - Minimum window substring](https://leetcode.com/problems/minimum-window-substring/description/) too.
