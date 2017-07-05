#ifndef HASH_H
#define HASH_H
#include <vector>
#define HASH_SIZE 256

struct HashItem {
    HashItem() {}
    HashItem(int v, int k) : val(v), key(k) {}
    int val;
    int key;
};

class Hash {
    public:
        Hash(int size = HASH_SIZE) : buckets_(size) {}
        void set(int val, int key) {
            int index = hashCal(key);
            buckets_[index].push_back(HashItem(val, key));
        }
        int get(int key) {
            int index = hashCal(key);
            for (auto e : buckets_[index]) {
                if (e.key == key) {
                    return e.val;
                }
            }
            return -1;
        }
    private:
        std::vector<std::vector<HashItem> > buckets_;
        size_t hashCal(int key) {
            return key % HASH_SIZE;
        }

};


#endif