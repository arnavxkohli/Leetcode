# K Closes Points To Origin

When you need to find `k` closest or farthest of something the first idea is to use a max-heap. Popping from a max heap always pops the max element. This ensures we keep the `k` smallest if we push and pop once the list size grows to be `k`. For `k` largest, it is the same approach but with a min-heap (Python's default).
