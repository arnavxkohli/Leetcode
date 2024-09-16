# Check if it is possible to split array

Two approaches detailed. The python approach is DP, and a little bit stupid. This question has a very elegant greedy solution. The constraints mention that you can split one array into a single element array every single time. Keeping this in mind, if you encounter any two consecutive elements whose sum is greater or equal to the target, you can keep them for last and perform all the splits (splitting one element at a time). As long as those two elements are last you will always have a valid array.
