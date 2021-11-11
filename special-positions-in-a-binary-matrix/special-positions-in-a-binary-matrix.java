class Solution {
    public int numSpecial(int[][] mat) {
        
        int special = 0, m = mat.length, n = mat[0].length;

        int row[] = new int[m], col[] = new int[n];
        
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
}