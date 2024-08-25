# Longest Common Subsequence

This is a standard dynamic programming tabulation problem, it just requires some key observations but is honestly not too difficult. There are two test cases detailed for this below:

| |empty | a | b | c | d | e |
|---|---|---|---|---|---|---|
| empty | 0 | 0 | 0 | 0 | 0 | 0 |
| a | 0 | 1 | 1 | 1 | 1 | 1 |
| c | 0 | 1 | 1 | 2 | 2 | 2 |
| e | 0 | 1 | 1 | 2 | 2 | 3 |


| | empty | a | b | c | d | e |
|-------|-------|---|---|---|---|---|
| empty | 0     | 0 | 0 | 0 | 0 | 0 |
| x     | 0     | 0 | 0 | 0 | 0 | 0 |
| b     | 0     | 0 | 1 | 1 | 1 | 1 |
| y     | 0     | 0 | 1 | 1 | 1 | 1 |
| c     | 0     | 0 | 1 | 2 | 2 | 2 |
| e     | 0     | 0 | 1 | 2 | 2 | 3 |
