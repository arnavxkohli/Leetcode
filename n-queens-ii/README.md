# N Queens II

To get the available positions, you have to realize that on a square chessboard, the diagonals are at `x-my=0` and `x+my=0`. The columns are determined by the lines `x=c`. Using these lines, we can track if there is a queen already on one of them depending on the slope. We backtrack with these constraints till we get to a point where we have covered all `n` rows.
