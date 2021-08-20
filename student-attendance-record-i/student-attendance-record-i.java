class Solution {
    public boolean checkRecord(String s) {
        
        int a = 0, l = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            
            if (s.charAt(i) == 'A') { ++a; }
            
            if (s.charAt(i) == 'L') { ++l; }
            
            else { l = 0; }
            
            if (l >= 3) { return false; }
        }
        
        
        return (a < 2);
    }
}