# Operations on Tree

Goddamn, man. This questions is definitely larping as a medium. With C++ the implementation took hours (mostly because I would do it then get stuck and then do it again), but came up with it on my own so won't forget it. The key idea is to store a mapping for each `Node` within an array in the actual class. This speeds up look-up considerably. Another important thing is to store a pointer to the ancestor node, which makes going up the tree quicker to check if any ancestor is locked.
Other than that, nothing too complicated. I have used an `optional` type here which is fun. It was introduced in C++ 17 though, so be careful. The alternative is to use a `nullptr`. 
Another important thing is memory dellocation. Note the way I have done it.
Be careful with the 0th index and make sure to allocate memory for every node in the array before-hand. Also store the number of elements in the array for deallocation.

