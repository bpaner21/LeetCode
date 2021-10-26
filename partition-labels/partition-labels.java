class Solution {
    public List<Integer> partitionLabels(String s) {
        
        int lastIndex[] = new int[26];
        
        ArrayList<Integer> partitions = new ArrayList<>();
        
        // record the rightmost index of each letter in s
        for (int i = 0; i < s.length(); ++i) {
            
            lastIndex[s.charAt(i) - 'a'] = i;
        }
        
        // using the record of the rightmost indices as end points,
        // create partitions that contain every appearnce of the letters they hold
        for (int left = 0; left < s.length(); ++left) {
            
            int right = left;
            
            int partitionEnd = lastIndex[s.charAt(left) - 'a'];
            
            while (left < partitionEnd) {
                
                ++left;
                
                partitionEnd = Math.max(partitionEnd, lastIndex[s.charAt(left) - 'a']);
            }
            
            partitions.add(left - right + 1);
        }
        
        return partitions;
    }
}