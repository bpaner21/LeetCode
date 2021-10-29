class Solution {
    public int longestConsecutive(int[] nums) {
        
        HashSet<Integer> s = new HashSet<>();
        
        for (int i : nums) { s.add(i); }
        
        int lcs = 0;
        
        for (Integer j : s) {
            
            if (s.contains(j - 1) == false) { 
                
                int current = j + 1;
                
                while (s.contains(current) == true) { ++current; }
                
                lcs = Math.max(lcs, current - j);
            }
        }
        
        return lcs;
    }
}