from typing import List
from collections import Counter, defaultdict


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []
        p_count = Counter(p)
        s_count = {key:0 for key, _ in p_count.items()}
        need = len(p_count.values())
        have = 0
        res = []
        for l in range(len(p)):
            if s[l] in p_count:
                s_count[s[l]] += 1
                if s_count[s[l]] == p_count[s[l]]:
                    have += 1
        if have == need:
            res.append(0)
        for r in range(len(p), len(s)):
            l = r-len(p)
            if s[l] in p_count:
                if s_count[s[l]] == p_count[s[l]]:
                    have -= 1
                s_count[s[l]] -= 1
            if s[r] in p_count:
                s_count[s[r]] += 1
                if s_count[s[r]] == p_count[s[r]]:
                    have += 1
            if have == need:
                res.append(l+1)
        return res