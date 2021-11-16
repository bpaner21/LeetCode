class KthLargest {
    
    private PriorityQueue<Integer> _n;
    
    private int _k;

    public KthLargest(int k, int[] nums) {
        
        _n = new PriorityQueue<Integer>();
        
        _k = k;
        
        for (int i : nums) {
            
            _n.add(i);
            
            if (_n.size() > _k) { _n.poll(); }
        }
    }
    
    public int add(int val) {
     
        _n.add(val);
        
        if (_n.size() > _k) { _n.poll(); }
        
        return _n.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */