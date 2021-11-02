class Solution {
    public String truncateSentence(String s, int k) {
        
        int spaces = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            
            if (s.charAt(i) == ' ') { ++spaces; }
            
            if (spaces == k) { return s.substring(0, i); }
        }
        
        return s;
    }
}