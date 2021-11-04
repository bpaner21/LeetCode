class Solution {
    public int longestWPI(int[] hours) {
        
        if (hours.length == 1) { return (hours[0] > 8 ? 1 : 0); }
        
        int score = 0, maxInterval = 0;
        
        HashMap<Integer, Integer> map = new HashMap();
        
        for (int i = 0; i < hours.length; ++i) {
            
            score += (hours[i] > 8 ? 1 : -1);
            
            // only record the first instance that a specific score is found
            if (!map.containsKey(score)) { map.put(score, i); }
            
            if (score > 0) { // if there have been more tiring days than not (strictly incrementing interval)
                
                maxInterval = i + 1; 
            }
            else if (map.containsKey(score - 1)) { // if there exists an incrementing interval
                
                maxInterval = Math.max(maxInterval, i - map.get(score - 1));
            }
        }
        
        return maxInterval;
    }
}