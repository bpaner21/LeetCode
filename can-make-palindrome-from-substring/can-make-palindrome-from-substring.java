class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        
        int[][] letterCount =  new int[s.length() + 1][26];
        
       for (int i = 1; i <= s.length(); ++i) {
           
           for (int j = 0; j < 26; ++j) {
               
               letterCount[i][j] = letterCount[i-1][j];
           }
           
           ++letterCount[i][s.charAt(i - 1) - 'a'];
       }
        
        ArrayList<Boolean> canPalindrome = new ArrayList<>();
        
        for (int x = 0; x < queries.length; ++x) {
            
            int left = queries[x][0], right = queries[x][1], k = queries[x][2], t = 0;
            
            for (int y = 0; y < 26; ++y) {
                
                t += (letterCount[right + 1][y] - letterCount[left][y]) % 2;
            }
            
            canPalindrome.add(t / 2 <= k);
        }
        
        return canPalindrome;
    }
}