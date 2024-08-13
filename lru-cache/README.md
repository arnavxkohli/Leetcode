# LRU Cache

This is a heavily nuanced doubly linked list problem. Therefore, the main good solution to look at for a deep understanding is the C++ solution. The types give a more robust infrastructure for the code.

- We need a `struct` for the nodes of the lru cache. Since it is doubly linked it is good to have next and prev pointers. We can also keep the key and value **both**, we might need the key to see what the current lru element is or after eviction.
- The lru cache itself needs `occupancy` for how full it is, `capacity` for max size, an `LRU CacheNode` for the lru element and also an `MRU CacheNode` for the mru element.
- Obviously we need an `unordered_map` for the cache itself.

General takeaways:
1. If the cache has one element, then the key is guaranteed to be the MRU and the LRU if in the cache.
2. If the cache has two elements, then the key is either the MRU or LRU, again guaranteed.
3. If the cache has only one element and it is evicted, then both LRU and MRU need to point to `nullptr`. This is easier for LRU but requires extra care for MRU.
4. In case MRU is `nullptr` when adding to the cache, then do not perform any `MRU->next` step.
5. In case LRU is `nullptr` when adding to the cache, then set the current value added to be the `LRU`

The Get operations can be broken down into:
1. Get when key is not in cache: In this case, simply return -1
2. Get when key is in cache and it is the `MRU`: This always happens for a single element cache. In such a case simply returning the `cache[key]->value` is enough (remember that the map values are cache nodes, not the values themselves).
3. Get when key is in cache and it is the `LRU`: This does happen for a single element cache, but try to structure the code so that you deal with those in the condition above. In such a case, simply shift the lru to the next pointer and bring this node to the `MRU` by making `MRU->next` point to the current element and the current element's `prev` point to the current `MRU`. Then simply do `this->MRU = current_element`.
4. Get when key is in the middle: Probably the most involved? Put current element's previous's next as the current element's next and also current element's next's previous as the current element's previous. Basically visualize removing the element from in between. Remember that if you have got this far in the checks, you are guaranteed to have 3 elements. The last step is the same as the previous one (move current element to MRU).

The 3rd and 4th point would greatly benefit from a function which brings a key to the `MRU`. This function should be called only after checking the current element is not already `MRU`. You can add a guard clause for this but I think logically it is clearer if called only when the element is not `MRU`

The Set operations can be broken down into:
1. Set when key is in cache and is MRU: simply change the value of the element paired with the key.
2. Set when key is in cache and is not MRU: change the value first obviously, and then call the function mentioned above.
3. Set when key not in cache:

    - If occupancy is equal to capacity before adding element: Need to evict here. Shift the `LRU` to `LRU->next` and delete the key - value pair associated with `LRU->next->key`. If the occupancy is now zero (and the `LRU` is now `nullptr`), then set `MRU` to also be `nullptr`
    - Create the node and add it to the cache. Set the previous value for the node to be the `MRU`. If the `MRU` is not `nullptr` then set `MRU->next` to be the current node which was added. Finally, set `MRU` to be the current node. In case the `LRU` was `nullptr`, then set the `LRU` to also be the current node. Increment occupancy in the end.
