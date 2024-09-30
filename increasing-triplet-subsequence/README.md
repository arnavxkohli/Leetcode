# Increasing triplet subsequence

Pretty embarassing I didn't get this first try. Maintain the smallest and second smallest as variables. If the smallest is greater or equal to the current, set smallest to current. Else if the second smallest is greater or equal to the current, set second smallest to current. Else, return True. The equal to case is important because of subsequences of the same number repeated again and again, which would return true, if the comparison was a hard greater than.
