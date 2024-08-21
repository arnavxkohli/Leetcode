# Hand of Straights

This question is quite easy overall. Just maintain a count of all the cards present in the deck. Sort the deck and then iterate through it. If encountering a card `x` which has non-zero frequency, try incrementing till you reach `x + groupSize - 1`. If you are unable to reach this, it isn't possible. Do this till you go through the entire array.

The first condition you need to check is that the deck can be perfectly divided by `groupSize`
