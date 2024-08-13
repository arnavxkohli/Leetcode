#include <unordered_map>

struct CacheNode {
  int key;
  int value;
  CacheNode *next;
  CacheNode *prev;
  CacheNode(int _key, int _value, CacheNode *_prev=nullptr) : key(_key), value(_value), next(nullptr), prev(_prev) {}
};

class LRUCache {
private:
  std::unordered_map<int, CacheNode*> cache;
  CacheNode *lru;
  CacheNode *mru;
  int capacity;
  int occupancy;

public:
  LRUCache(int capacity) : capacity(capacity) {
    this->occupancy = 0;
    this->lru = nullptr, this->mru = nullptr;
  }

  void bringToMRU(int key) {
    if(this->mru->key == key) return;
    // This function is only called when size of cache is at least 2. If it is 2 then lru is the lower and mru is the higher
    if(this->lru->key == key) {
      // Shift LRU by one
      this->lru = this->lru->next;
    } else {
      // now lru is 1, desired key is 2, mru is 3. we need 2 to be 3
      cache[key]->prev->next = cache[key]->next;
      cache[key]->next->prev = cache[key]->prev;
      // 1 points to 3 and 3 points to 1
    }
    // Place current cache key at the front
    this->mru->next = cache[key];
    cache[key]->prev = this->mru;
    // Shift MRU to current cache key
    this->mru = cache[key];
  }

  int get(int key) {
    if(cache.find(key) == cache.end()) {
      return -1;
    }
    // from this point on the key has to be in the cache so
    if(this->occupancy > 1) {
      // need to bring the current element to mru
      this->bringToMRU(key);
    }
    // if lru == mru then no need to do anything
    return cache[key]->value;
  }

  void put(int key, int value) {
    if(cache.find(key) != cache.end()) {
      // Key already in cache
      cache[key]->value = value;
      if(this->occupancy > 1) {
        this->bringToMRU(key);
      }
    } else {
      // Key not in cache
      if(this->occupancy == this->capacity) {
        this->cache.erase(this->lru->key);
        this->lru = this->lru->next;
        this->occupancy--;
        if(this->lru == nullptr) this->mru = nullptr;
      }
      CacheNode *node = new CacheNode(key, value, this->mru);
      if(this->mru != nullptr) { // if cache empty avoid
        this->mru->next = node;
      }
      this->mru = node;
      if(this->lru == nullptr) { // cache was empty
        this->lru = node;
      }
      this->cache[key] = node;

      this->occupancy++;
    }
  }
};