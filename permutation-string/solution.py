from typing import Counter


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1_freq = Counter(s1)
        s2_freq = {}
        l = 0
        for r in range(len(s2)):
            if s2[r] in s1_freq:
                s2_freq[s2[r]] = s2_freq.get(s2[r], 0) + 1
                while s2_freq[s2[r]] > s1_freq[s2[r]]: # this is a pseudo invalid state, bring it to a pseduo valid state
                    s2_freq[s2[l]] -= 1
                    l += 1
                if s1_freq == s2_freq: return True # only return true if in valid, not pseudo-valid.
            else:
                l = r+1 # "skip over" the current index
                s2_freq = {} # start over from the new r index in the next iteration
        return False