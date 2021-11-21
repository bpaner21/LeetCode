class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_set<char> p;
        
        int first[26], last[26], count = 0;
        
        fill_n(first, 26, INT_MAX);
        fill_n(last, 26, 0);
        
        for(int i = 0; i < s.size(); ++i) {
            
            int letter = s[i] - 'a';
            
            first[letter] = min(first[letter], i);
            last[letter] = i;
        }
        
        for (int j = 0; j < 26; ++j) {
            
            if (first[j] < INT_MAX) {
            
                p.clear();
                
                for (int k = first[j] + 1; k < last[j]; ++k) { p.insert(s[k]); }

                count += p.size();
            }
        }
        
        return count;
    }
};