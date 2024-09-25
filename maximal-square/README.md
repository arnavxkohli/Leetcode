# Maximal Square

Classic DP problem. You can modify the matrix itself, but that gets messy. This is one of the rare cases where it is best to create an extra matrix wherein you do the modifications. Good problem overall. Intuition is basically to update dp only when you have a 1 in the matrix. You need to update it with the minimum of the side lengths from the top left, top and left cells. This is because the square can only be as big as the minimum of the three.
