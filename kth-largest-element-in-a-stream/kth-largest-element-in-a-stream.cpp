class KthLargest {
private:
    
    priority_queue<int, vector<int>, greater<int>> _n {};
    
    int _k;
    
public:
    KthLargest(int k, vector<int>& nums) : _k(k) {
        
        for (int i = 0; i < nums.size(); ++i) {
            
            _n.push(nums[i]);
            
            if (_n.size() > _k) { _n.pop(); }
        }
    }
    
    int add(int val) {
        
        _n.push(val);
        
        if (_n.size() > _k) { _n.pop(); }
        
        return _n.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */