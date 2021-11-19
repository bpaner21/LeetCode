class Solution {
    public boolean areNumbersAscending(String s) {
        
        int prev = 0, cur = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            
            char ch = s.charAt(i);
            
            if (Character.isDigit(ch)) {
                
                cur = cur * 10 + (ch - '0');
            }
                
            else if (cur != 0) {
                
                if (prev >= cur) { return false; }
                    
                prev = cur;
                
                cur = 0;
            }
        }
        
        return cur == 0 || prev < cur;
    }
}