class Solution {
    public boolean halvesAreAlike(String s) {
        
        String a = s.substring(0, s.length() / 2),
                b = s.substring(s.length() / 2);
        
        return vowelCount(a) == vowelCount(b);
    }
    
    private int vowelCount(String s) {
        
        int count = 0;
        
        for (char c : s.toCharArray()) {
            
            if (isVowel(c)) {++count;}
        }
        
        return count;
    }
    
    private boolean isVowel(char ch) {
        
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
}