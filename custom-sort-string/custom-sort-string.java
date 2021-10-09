class Solution {
    public String customSortString(String order, String s) {
        
        // StringBuilder has better performance than String
        StringBuilder answer = new StringBuilder();
        
        // record the frequency of characters in s
        int frequency[] = new int[26];
        
        for (char i : s.toCharArray()) {
            
            ++frequency[i - 'a'];
        }
        
        // iterating through the characters in the custom order,
        // add them to the return string, if they appear in s,
        // while removing them from the frequency array
        for (char j : order.toCharArray()) {
            
            while (frequency[j - 'a'] > 0) {
                
                answer.append(j);
                
                --frequency[j - 'a'];
            }
        }
        
        // add the remaining characters from s
        // to the return string in alphabetical order
        for (char k = 'a'; k <= 'z'; ++k) {
            
            while (frequency[k - 'a'] > 0) {
                
                answer.append(k);
                
                --frequency[k - 'a'];
            }
        }
        
        return answer.toString();
    }
}
