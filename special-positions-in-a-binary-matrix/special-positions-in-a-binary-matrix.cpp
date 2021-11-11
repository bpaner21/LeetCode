class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int special = 0, m = mat.size(), n = mat[0].size();
        
        vector<int> row(m, 0), col(n, 0);
        
        for (int i = 0; i < m; ++i) {
            
            for (int  j = 0; j < n; ++j) {
                
                if (mat[i][j] == 1) {
                    
                    ++row[i];
                    ++col[j];
                }
            }
        }
        
        for (int k = 0; k < m; ++k) {
            
            for (int l = 0; l < n; ++l) {
                
                if (mat[k][l] == 1 && row[k] == 1 && col[l] == 1) { ++special; }
            }
        }
        
        return special;
    }
};