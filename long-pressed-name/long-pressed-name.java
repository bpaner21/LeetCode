class Solution {
    public boolean isLongPressedName(String name, String typed) {
        
        // if the first characters do not match,
        // there is no way to make typed = name
        if (name.charAt(0) != typed.charAt(0)) { return false; }
        
        int n = 1;
        
        for (int t = 1; t < typed.length(); ++t) {
            
            if (n < name.length() && name.charAt(n) == typed.charAt(t)) { ++n; }
            
            // if there is a character in typed that would not be
            // in the same relative position in name
            else if (typed.charAt(t) != typed.charAt(t - 1)) { return false; }
        }
        
        return n == name.length();
    }
}