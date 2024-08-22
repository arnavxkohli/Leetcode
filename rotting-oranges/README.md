# Rotting Oranges

Pretty simple conditional bfs, with a slight trick involved. The key is to never convert a fresh orange to a rotten orange. For each rotten orange, carry out a bfs till you reach a point where you are not benefitting by carrying on with the bfs.

The benefit here is a reduction in time. Only continue the bfs on those nodes which output a lower time when navigated to from a rotten orange.
