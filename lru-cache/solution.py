class CacheNode:
    def __init__(self, key, value, prev):
        self.key, self.value, self.next, self.prev = key, value, None, prev


class LRUCache:

    def __init__(self, capacity: int):
        self.cache = dict()
        self.occupancy = 0
        self.capacity = capacity
        self.mru = None
        self.lru = None

    def bring_to_mru(self, key: int) -> None:
        if self.lru.key == key:
            self.lru = self.lru.next
        else:
            self.cache[key].prev.next, self.cache[key].next.prev = self.cache[key].next, self.cache[key].prev
        self.mru.next, self.cache[key].prev = self.cache[key], self.mru
        self.mru = self.cache[key]

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        # key is in the cache from here on out
        if self.mru.key != key: # this covers capacity is 1 case
            self.bring_to_mru(key)
        return self.cache[key].value

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache[key].value = value
            if self.mru.key != key:
                self.bring_to_mru(key)
        else:
            if self.capacity == self.occupancy:
                self.occupancy -= 1
                del self.cache[self.lru.key]
                self.lru = self.lru.next
                if self.lru is None: # cache had only 1 element
                    self.mru = None
            node = CacheNode(key, value, self.mru)
            if self.mru:
                self.mru.next = node
            self.mru = node
            self.cache[key] = node
            if self.lru is None: # single element rn
                self.lru = node
            self.occupancy += 1


# capacity 1 -> lru = mru
# capacity 2 -> lru is smaller, mru is larger
