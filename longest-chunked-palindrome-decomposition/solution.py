class Solution:
    def __init__(self):
        self.mod = 10 ** 9 + 7
        self.base = 29
        self.text = None

    def dp(self, l, r):
        if r < l:
            return 0
        lhash, rhash = 0, 0
        r_power = 1
        equal_found = False
        while l < r and not equal_found:
            lhash = (lhash * self.base + ord(self.text[l]) - ord('a') + 1) % self.mod
            rhash = ((ord(self.text[r]) - ord('a') + 1) * r_power + rhash) % self.mod
            r_power = (r_power * self.base) % self.mod
            l, r = l+1, r-1
            if lhash == rhash:
                equal_found = True
        return 2 + self.dp(l, r) if equal_found else 1

    def longestDecomposition(self, text: str) -> int:
        self.text = text
        return self.dp(0, len(text)-1)
