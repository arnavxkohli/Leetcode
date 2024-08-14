# Implement Trie (Prefix Tree)

There are two solutions highlighted for this problem.

1. Common to the two solutions, We need a pointer to a `TrieNode` struct within our `Trie` implementation.
2. We need spaces within the `TrieNode` for the characters that are being currently used (either with a map or 26 element array) and a flag to indicate the end of our word.
3. To ensure we do not override progress, we need to check if the next `TrieNode` or `char` or `index` is set.
4. It is a good idea to hold a pointer at the beginning (called `curr`) which will do the iterating.

## Hashmap solution
Easier solution? Just set the `unordered_map` within the `TrieNode` struct and iterate through it, as you go from `TrieNode` to `TrieNode`. Remember that you have to set the end value at the very end, unlike the array case

## Array solution
This is faster, and probably more efficient memory wise. The only quirk you have to take care of is the end condition. Go from `TrieNode` to `TrieNode` from your base `Trie` and you should be fine.
