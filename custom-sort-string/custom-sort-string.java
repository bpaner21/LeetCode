class Solution {
    public String customSortString(String order, String s) {
        
        StringBuilder answer = new StringBuilder();
        
        int frequency[] = new int[26];
        
        for (char i : s.toCharArray()) {
            
            ++frequency[i - 'a'];
        }
        
        for (char j : order.toCharArray()) {
            
            while (frequency[j - 'a'] > 0) {
                
                answer.append(j);
                
                --frequency[j - 'a'];
            }
        }
        
        for (char k = 'a'; k <= 'z'; ++k) {
            
            while (frequency[k - 'a'] > 0) {
                
                answer.append(k);
                
                --frequency[k - 'a'];
            }
        }
        
        return answer.toString();
    }
}