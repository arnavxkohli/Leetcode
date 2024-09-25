# Extra characters in a string

This is similar to the dynamic programming question, word break. Basically, for each word in the dictionary, iterate through it and if it fits with the starting character then good. In all cases, try skipping the current character. The two choices you have are to use a word from the dictionary or to skip it and leave a character behind, which will be one of the extra characters.
