class Solution {
    
    private int _row, _col, _total;
    
    private Random _random;
    
    private HashMap<Integer, Integer> _map;
    

    public Solution(int m, int n) {
        
        _row = m;
        _col = n;
        _total = m * n;
        
        _random = new Random();
        
        _map = new HashMap();
    }
    
    public int[] flip() {
        
        int random = _random.nextInt(_total);
        
        --_total;
        
        int flipped = _map.getOrDefault(random, random);
        
        int t = _map.getOrDefault(_total, _total);
        
        _map.put(random, t);
        
        _map.put(_total, flipped);
        
        return new int[] { flipped / _col, flipped % _col };
    }
    
    public void reset() {
        
        _total = _row * _col;
        
        return;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(m, n);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */