# Remove Nth Node From End Of List

I think a basic intuition you have to have when you have such questions where you think you would need to traverse the list twice, you can use fast and slow pointers. The slow pointer only gets activated after `n` iterations.

To ensure edge case of `n = 1` and single element list doesn't get you, you can use a dummy pointer as the head and return `dummy.next`.
