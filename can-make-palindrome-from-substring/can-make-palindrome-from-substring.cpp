class Solution {
public:
    vector<bool> canMakePaliQueries(string& s, vector<vector<int>>& queries) {
        
        int n = s.size() + 1;
        
        int oddCount[n][26];
        
        for (int a = 0; a < 26; ++a) { oddCount[0][a] = 0; }
        
        for (int i = 1; i <= s.size(); ++i) {
            
            for (int j = 0; j < 26; ++j) {
                
                oddCount[i][j] = oddCount[i-1][j];
            }
            
            ++oddCount[i][s[i-1] - 'a'];
        }
        
        vector<bool> canPalindrome {};
        
        for (int x = 0; x < queries.size(); ++x) {
            
            int left = queries[x][0], right = queries[x][1], k = queries[x][2], t = 0;
            
            for (int y = 0; y < 26; ++y) {
                
                t += (oddCount[right + 1][y] - oddCount[left][y]) % 2;
            }
            
            canPalindrome.push_back(t / 2 <= k);
        }
        
        return canPalindrome;
    }
};