class Solution {
public:
    string customSortString(string& order, string& s) {
        
        int frequency[26] = {0};
        
        string answer = "";
        
        // record the frequency of characters in s
        for (char i : s) {
            
            ++frequency[i - 'a'];
        }
        
        // iterating through the characters in the custom order,
        // add them to the return string, if they appear in s,
        // while removing them from the frequency array
        for (char j : order) {
            
            while (frequency[j - 'a'] > 0) {
                
                answer += j;
                
                --frequency[j - 'a'];
            }
        }
        
        // add the remaining characters from s
        // to the return string in alphabetical order
        for (int k = 0; k < 26; ++k) {
            
            while (frequency[k] > 0) {
                
                answer += k + 'a'; 
                
                --frequency[k];
            }
        }
        
        return answer;
    }
};