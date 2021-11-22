class Solution {
private:
    
    default_random_engine engine;
    
    int _row, _col, _total;
    
    unordered_map<int, int> _map;
    
public:
    Solution(int m, int n) : _row(m), _col(n), _total(m * n) {
        
    }
    
    vector<int> flip() {
        
        --_total;
        
        uniform_int_distribution<int> distribution(0, _total);
        
        int rand = distribution(engine);
        
        int flipped = _map.find(rand) != _map.end() ? _map[rand] : rand;
        
        int t = _map.find(_total) != _map.end() ? _map[_total] : _total;
        
        _map[rand] = t;
        
        _map[_total] = flipped;
        
        return {flipped / _col, flipped % _col};
    }
    
    void reset() {
        
        _total = _row * _col;
        
        return;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */