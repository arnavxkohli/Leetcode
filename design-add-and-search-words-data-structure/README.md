# Design Add and Search Words Data Structure

This question involves designing a data structure which efficiently adds and searches for words within it. The only caveat is the '.' operator which slightly complicates things. It is like a regex where in you can replace it with any character

This suggests we use a recursion to search for all the possible values it can be.

Not much else to it. Have used a `unique_ptr` which will automatically manage memory and reduce the memory usage.
