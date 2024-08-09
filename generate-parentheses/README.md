# Generate Parentheses

This is a relatively simple backtracking problem. A good trick to know when a problem involves backtracking is to see whether you have a decision tree which you can DFS to find solutions. Similar to permutations and combinations, it deals with tracking all possible answers to a particular question, and has an exponential complexity.

In this particular case, the decisions are:
1. If the current string has reached `2n` length then it can be added to the result. Note that this requires you to make sure you are only forming well-formed parentheses in the other decision steps.
2. Use open bracket: This is only possible if you haven't used `n` open brackets. If the amount you have used is less than `n` then go ahead and make this decision
3. Use closed bracket: This is possible if the number of closed brackets used is **strictly less than** the amount of open brackets used. If so, go ahead and make this decision

For all these decisions, the state that needs to be "tracked" (carried forward) is: (current string, open brackets used, closed brackets used).

With this intuition the question can be solved rather easily.
