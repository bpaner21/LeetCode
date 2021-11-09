class LRUCache {
    
private:
    
    // cache capacity
    int _capacity;
    
    // map<key, list<key, value>::iterator>
    unordered_map<int, list<pair<int,int>>::iterator> _map;
    
    // list<key, value>
    // pairs closer to front are more recently accessed
    //
    // key-value pair at back of list is least recently accessed
    list<pair<int,int>> _list;
    
public:
    
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        
        auto itr = _map.find(key);
        
        
        // if key doesn't exist in map, return -1
        if (itr == _map.end()) { return -1; }
        
        
        // move most recently accesed key-value pair to front of list
        _list.splice(_list.begin(), _list, itr->second);
        
        // return the value associated with the key
        return itr->second->second;
    }
    
    void put(int key, int value) {
        
        auto itr = _map.find(key);
        
        
        // if key exists in map, list only needs to be updated
        if (itr != _map.end()) { 
         
            // update the appropriate key-value pair
            // using the iterator found in the map
            itr->second->second = value;
            
            // move most recently accesed key-value pair to front of list
            _list.splice(_list.begin(), _list, itr->second);
            
            return;
        }
        
        
        // if key does not exist, check if cache is at max capacity
        if (_map.size() == _capacity) {
            
            // record key of least used cache element
            int eKey = _list.back().first;
            
            // remove least used cache element from list
            _list.pop_back();
            
            // remove least used cache element from map
            _map.erase(eKey);
        }
        
        // add new key-value pair to front of list
        _list.push_front(make_pair(key, value));
        
        // add a new key-iterator pair to the map
        _map[key] = _list.begin();
        
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */