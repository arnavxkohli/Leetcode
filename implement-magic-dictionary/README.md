# Implement magic dictionary

Like most questions which are a variant on a trie, the basic implementation is pretty straightforward. The replace logic is a bit tricky. If we do find a word that works, then keep replace as it is DO NOT set it to true. If we find a letter which matches within the prefix, then no need to use up replace (if we have any left). If we don't the only option is to use up a replace (if we have one). During the replace, we need to ensure we only replace with non-null branches in the trie.

Be careful with the `end` logic. If we reach a point where we have reached the end of the word, we need to check with the trie that end is valid for our current string.
