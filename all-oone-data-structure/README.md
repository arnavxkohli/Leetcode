# All O'One data structure

This question is the worst. Trick is to store the counts as a doubly linked list like an LRU cache. There are a LOT of edge cases here. You also want a mapping of the key to the map it belongs to so that you know for sure you can find the mapping. Maintain the minimum and maximums like the lru and mru, for O(1) minimum and maximum lookups. Maintain a set of words within each node for ease of removal.

## Inc

- If the key is not in the map, add it to the map with a count of 1. This has three cases. In all three cases, remember to actually insert the word within the newly created nodes, and to map the new nodes back to the key.
  - Empty list: Make the `minNode` and `maxNode` equal to the new node.
  - `minNode->count` is greater than 1: The new node's `next` pointer should be the current `minNode`, make sure to map the current `minNode`'s `prev` pointer back to the new node. After this is done, shift the `minNode` to the new node.
  - `minNode->count` is 1: Simplest case, simply make sure you follow the rules of insertion. No need to create a new node.
- If the key is in the map, find the node to which it belongs. Make sure to then remove the word from that node's set. There are still two edge cases to consider here. Once the node to be inserted in has been found/created (based on the cases), make sure to add the key to that node's words and to map the new node back to the old key. You also need to make sure you delete the old node if this key was its only inhabitant.
  - If the next node does not exist: We need to create the new node, map the new node's prev back to the old node, map the old node's next to the new node, and then set the newly created node as the `maxNode`.
  - If the next node's count is not the increment of the old node's count: This means we have to insert a new node between the old current node and the old next node. Make sure the old next node's previous is set to the new node, the new node's next is set to the old next, the new node's prev is set to the old current, the old current's next is set to the new node.
- Removing has edge cases of the next node not existing, the previous node not existing, the current node being the minNode and the current node being the maxNode. Once covered the logic is straightforward.

## Dec

This is the exact reverse to the inc case, except the node is guaranteed to exist. The only real edge case here is if the node's count is 1, in which case we need to remove the node from the map.

## GetMaxKey and GetMinKey

Trivial, just return the maxNode's words and minNode's first word respectively.
