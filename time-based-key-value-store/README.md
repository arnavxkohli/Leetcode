# Time Based Key-Value Store

This is a data structure design question. It implements a hash map kind of structure (key-value store) which has a timestamp associated with it. Every time a new element is added to the same key, it will be added with an increased timestamp.

We need to return the element with the greatest time `t` such that `t` is either less than or equal to the timestamp we provide for a particular key. If this is not possible we are meant to return an empty string.

There are two main empty string cases here:
1. If the key is not in the key-value store.
2. If there are only elements with values greater than the timestamp requested.

For all other cases, narrow the search range and then pick `r` if the timestamp at `mid` never equals the desired timestamp. We choose `r` because we know it will be lower than `l` and we want the highest value that is lower than the timestamp which is not the timestamp itself. `l` has potential to cross the timestamp's value on the `l == r` iteration. 
