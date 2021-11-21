class Solution {
    public int countPalindromicSubsequence(String s) {
        
        int count = 0;
        
        int first[] = new int[26], last[] = new int[26]; 
        
        Arrays.fill(first, Integer.MAX_VALUE);
        
        
        for(int i = 0; i < s.length(); ++i) {
            
            int letter = s.charAt(i) - 'a';
            
            first[letter] = Math.min(first[letter], i);
            last[letter] = i;
        }
        
        
        for (int j = 0; j < 26; ++j) {
            
            if (first[j] < last[j]) {

                count += s.substring(first[j] + 1, last[j]).chars().distinct().count();
            }
        }
        
        
        return count;
    }
}