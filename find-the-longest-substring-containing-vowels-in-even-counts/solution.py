class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        vowels = {'a':16, 'e':8, 'i':4, 'o':2, 'u':1}
        prefix_mask = {31: -1}
        running_sum = 31
        res = 0
        for i, char in enumerate(s):
            running_sum ^= vowels.get(char, 0)
            if running_sum not in prefix_mask:
                prefix_mask[running_sum] = i
            else:
                res = max(res, i - prefix_mask[running_sum])
        return res
