class Solution:

    # O(26n) solution
    def characterReplacementInefficient(self, s: str, k: int) -> int:
        max_length = 1
        frequency = [0] * 26
        l = 0
        for r in range(len(s)):
            frequency[ord(s[r]) - ord('A')] += 1
            while (r-l+1) - max(frequency) > k:
                frequency[ord(s[l]) - ord('A')] -= 1
                l += 1
            max_length = max(max_length, (r-l+1))
        return max_length

    # O(n) solution
    def characterReplacement(self, s: str, k: int) -> int:
        max_length = 1
        l = 0
        max_f = 0
        frequency = [0] * 26
        for r in range(len(s)):
            frequency[ord(s[r]) - ord('A')] += 1
            max_f = max(max_f, frequency[ord(s[r]) - ord('A')])
            while (r-l+1) - max_f > k:
                frequency[ord(s[l]) - ord('A')] -= 1
                l += 1
            max_length = max(max_length, r-l+1)
        return max_length