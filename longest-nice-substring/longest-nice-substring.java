class Solution {
    public String longestNiceSubstring(String s) {
        
        if (s.length() < 2) { return ""; }
        
        HashSet<Character> set = new HashSet();
        
        char ch[] = s.toCharArray();
        
        for (char c : ch) { set.add(c); }
        
        for (int i = 0; i < ch.length; ++i) {
            
            if (set.contains(Character.toUpperCase(ch[i])) &&
                    set.contains(Character.toLowerCase(ch[i]))) { continue; }
            
            String a = longestNiceSubstring(s.substring(0, i));
            
            String b = longestNiceSubstring(s.substring(i + 1));
            
            return (a.length() >= b.length() ? a : b);
        }
        
        return s;
    }
}