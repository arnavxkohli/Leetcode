# Rotate Image

The solution is rather trivial. To rotate by 90º you can observe that transposing the matrix and reversing each row works.
For an explanation, you can talk about how the indices interact with each other.

Use this solution in the end though. There is a more involved and complicated solution which may impress the interviewer if you show them. This involves realizing that you can do it one row at a time. Construct the row and convert it to a column. Keep track of indices you have displaced in a map and while reconstructing, use the displaced indices for the next row down.

To avoid redundant calculations, and flipping twice (in the transpose), you need to start the columns from the current row.

Another point to note is that for a 180º rotation, reverse the rows and then reverse the whole matrix (so the order of the rows). Or 90º flip twice.

For a 270º rotation, transpose and then reverse the columns, or 90º flip thrice.
