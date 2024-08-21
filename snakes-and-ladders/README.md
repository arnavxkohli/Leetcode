# Snakes and Ladders

This is a simple conditional bfs. The only real trick here is adjusting the row to stick to the boustrophedon. This can be done by checking the parity of the adjusted row, and adding the adjusted column to find the index. The alternating row column bit causes confusion.

Once there is a robust way to find the indices (can be tested), a graph can be constructed for only those values where there is a snake or a ladder.

Once both of these are done, run a conditional bfs. Break if `n^2` is found. Look if you can find any index in the appropriate range.
