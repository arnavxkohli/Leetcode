# Word Search II

Chuck all the words in the dictionary into a trie. After this, use recursive backtracking on the grid. The only tricky thing is that you need to keep the current word as a function parameter. There is a neat way to not revisit the same word again and again, and that is to set end to false if end is ever true when you first encounter it within a word.
