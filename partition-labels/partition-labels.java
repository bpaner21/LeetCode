class Solution {
    public List<Integer> partitionLabels(String s) {
        
        char ch[] = s.toCharArray();
        
        int lastIndex[] = new int[26];
        
        int size = ch.length;
        
        ArrayList<Integer> partitions = new ArrayList<>();
        
        // record the rightmost index of each letter in s
        for (int i = 0; i < size; ++i) {
            
            lastIndex[ch[i] - 'a'] = i;
        }
        
        // using the record of the rightmost indices as end points,
        // create partitions that contain every appearnce of the letters they hold
        for (int left = 0; left < size; ++left) {
            
            int right = left;
            
            int partitionEnd = lastIndex[ch[left] - 'a'];
            
            while (left < partitionEnd) {
                
                ++left;
                
                partitionEnd = Math.max(partitionEnd, lastIndex[ch[left] - 'a']);
            }
            
            partitions.add(left - right + 1);
        }
        
        return partitions;
    }
}