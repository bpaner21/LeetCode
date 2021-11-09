class LRUCache {
    
    private class Node {
        
        Node prev = null, next = null;
        
        int key, value;
        
        Node(int k, int v) {
            
            key = k;
            value = v;
        }
    }
    
    
    // cache capacity
    private int _capacity;
    
    // doubly-linked list of key-pairs
    // nodes closer to front are more recently accessed
    //
    // node before tail is least recently accessed element
    private Node _head = new Node(0, 0), _tail = new Node(0, 0);
    
    // _map<key, Node>
    private HashMap<Integer, Node> _map;
        

    public LRUCache(int capacity) {
        
        _capacity = capacity;
        _map = new HashMap();
        
        _head.next = _tail;
        _tail.prev = _head;
    }
    
    public int get(int key) {
        
        // if key exists in map
        // remove associated node from list
        // and place it at front of list
        if (_map.containsKey(key)) {
            
            Node n = _map.get(key);
            
            remove(n);
            
            push_front(n);
            
            return n.value;
        }
        
        return -1;
    }
    
    public void put(int key, int value) {
        
        if (_map.containsKey(key)) {
            
            Node n = _map.get(key);
            
            remove(n);
            
            n.value = value;
            
            push_front(n);
            
            return;
        }
        
        if (_map.size() == _capacity) {
            
            // remove least recently used element from map
            _map.remove(_tail.prev.key);
            
            // remove least recently used element from doubly-linked list
            remove(_tail.prev);
        }
        
        Node n = new Node(key, value);
        
        push_front(n);
        
        _map.put(key, n);
        
        return;
    }
    
    // insert new node at head of doubly-linked list
    private void push_front(Node n) {
        
        // connect n and head.next
        n.next = _head.next;
        
        _head.next.prev = n;
        
        // connect head and n
        n.prev = _head;
        
        _head.next = n;
        
        return;
    }
    
    // remove node from doubly linked list
    private void remove(Node n) {
        
        n.prev.next = n.next;
        
        n.next.prev = n.prev;
        
        return;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */