# Predict The Winner

This is classic DP, but with a twist. Whenever you have two parties involved, and they have competing interests, you have to turn the DP into a minimax problem. This is because you want to maximize your own score, while minimizing the opponent's score. This can be done by subtracting the next iteration of the DP from the current iteration. This is a very common pattern in DP problems.

It can also be done by calculating the minimum if it is not your turn, and the maximum if it is your turn. This is the same as the above, but it is a more intuitive way of thinking about it.
