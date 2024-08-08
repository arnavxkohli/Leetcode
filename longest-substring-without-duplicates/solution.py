class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0 # for empty string case
        l = 0
        encountered = set()
        for r in range(len(s)):
            while s[r] in encountered: # invalid window condition
                encountered.remove(s[l])
                l += 1
            encountered.add(s[r])
            max_length = max(max_length, r-l+1)
        return max_length