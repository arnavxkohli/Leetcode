# Longest Chunked Palindrome Decomposition

Even though I have used a dp, this question is actually solved greedily. When you have palindromes in near linear time, you can use a rolling hash technique as demonstrated in the code. This quickly allows you to check if the two ends form a palindrome, and the moment they do (greedy, remember!) you can add to the result and move on to the next iteration (recursion).
