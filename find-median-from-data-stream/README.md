# Find Median From Data Stream

Just maintain two heaps. The max heap is for the first n elements, the min heap for the last n elements. Use heappushpop to maintain the size of the heaps and auto-balance it. There should be no more than a difference of 1 between the two heaps. If the heaps are balanced, the median is the average of the two top elements. If the heaps are not balanced, the median is the top element of the min heap. It could be the max heap too, but keep insertions into the min heap if both heaps are equal to easily assign the signs.
