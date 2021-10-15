class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        if (s.length() <= 1) { return s.length(); }
        
        int chars[] = new int[256]; 
        
        int left = 0, right = 0, maxSize = Integer.MIN_VALUE, currentSize = 0;
        
        while (right != s.length()) {
            
            ++chars[s.charAt(right)];
            
            ++currentSize;
            
            if (chars[s.charAt(right)] > 1) {
                
                while (chars[s.charAt(right)] > 1) {

                    --chars[s.charAt(left)];

                    ++left;
                    
                    --currentSize;
                }
            }
            
            maxSize = currentSize > maxSize ? currentSize : maxSize;
            
            ++right;
        }
        
        return maxSize;
    }
}