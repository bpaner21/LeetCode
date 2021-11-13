class Solution {
    public boolean winnerOfGame(String colors) {
        
        int aCount = 0, bCount = 0, i = 0;
        
        while (i < colors.length()) {
            
            char ch = colors.charAt(i);
            int curCount = 0;
            
            while (i < colors.length() && colors.charAt(i) == ch) {
                
                ++i;
                ++curCount;
            }
            
            curCount = Math.max(0, curCount - 2);
            
            if (ch == 'A') { aCount += curCount; }
            
            else { bCount += curCount; } 
        }
        
        
        return aCount > bCount;
    }
}