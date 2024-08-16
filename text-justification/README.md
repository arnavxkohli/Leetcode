# Text Justification

This is the classic hard string problem. There are no real tricks to it really, solving it requires a good strategy to deal with the constraints given. In these kind of questions TLE is rarely an outcome if the solution works.

1. The length of any word will always be less than the maximum width of the line. This is given in the question. What this means is you start from a list containing the first word.
2. At each extra word add a space **BEFORE** it to ensure you are accounting for there being at least one space. You need to keep track of the total space used on this line so far as well. If adding 1 + the length of the word to the total space used on the line is less than or equal to the maximum width then just increment the total space and add the word to the current line.
3. If the space required by this word along with the space preceding it is too much, then you need to push the word to the next line. Add the previous line to the list of lines, **reset the total space to the length of the current word and the current line to only contain the current word.** If you reset them to empty and 0, then you are missing this word because it wasn't a part of the previous line.
4. Once this process is complete, it is possible that the last line hasn't been appended to the array, so make sure it is in case the length is not 0.

This completes the first phase which involves finding out which word fits on which line. This is arguably the easy part. The next part is for spaces:
1. If the word is the only one in the line then don't do anything. Just set the current line to be a string instead of an array.
2. If the line is the last one, then you have to left justify it (question constraints). To do this, ensure there is at least one space between each word and add the remaining spaces to the end.
3. In all other cases, first split the spaces evenly between the words and remove these spaces assigned from the total spaces. Don't construct the line yet. Keep an array for spaces. After this, assign one more space in a round-robin approach (since it is a circular array now, use a `mod(%)` to wrap around). Once there are no more spaces, you can construct the word trivially.
4. In the last point, you can use a `mod` for the total spaces too. This is because the left over spaces will always be the remainder from the division.

In each of these cases, you need to assign the line once re-constructed as a string back to the lines list.
