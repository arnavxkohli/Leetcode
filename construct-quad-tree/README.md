# Construct Quad Tree

This question is such an insane headache. Just remember that without an explicit cast, division in C++ gives a float. Apart from this. It is very memory intensive to keep providing a new grid to functions down the recursion chain. You want to pass the indices bounding the correct region instead.

Just use a classic DFS approach by splitting the region into 4 along the combinations of `r`, `r+n/2` & `c`, `c+n/2`.
