class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        dp = [0] * len(s)
        for i in range(len(s)-1, -1, -1):
            curr_dp = dp[:i] + [1] + dp[i+1:]
            for j in range(i+1, len(s)):
                if s[i] == s[j]:
                    curr_dp[j] = 2 + dp[j-1]
                else:
                    curr_dp[j] = max(dp[j], curr_dp[j-1])
            dp = curr_dp
        return dp[-1]