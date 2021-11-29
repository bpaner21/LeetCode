class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        bool r0 = false, c0 = false;
        
        
        // check if there is a zero in the first row
        for (int i = 0; i < row; ++i) {
            
            if (matrix[i][0] == 0) {
                
                r0 = true;
                break;
            } 
        }
        
        // check if there is a zero in the first column
        for (int j = 0; j < col; ++j) {
            
            if (matrix[0][j] == 0) {
                
                c0 = true;
                break;
            }
        }
        
        
        // check for zeros on any of the other rows or columns
        for (int k = 1; k < row; ++k) {
            for (int l = 1; l < col; ++l) {
                
                // mark the rows and columns of any 0 element
                if (matrix[k][l] == 0) {
                    
                    matrix[k][0] = 0;
                    matrix[0][l] = 0;
                }
            }
        }
        
        // zero all marked indices
        for (int k = 1; k < row; ++k) {
            for (int l = 1; l < col; ++l) {
                
                if (matrix[k][0] == 0 || matrix[0][l] == 0) {
                    
                    matrix[k][l] = 0;
                } 
            }
        }
        
        
        // zero the first row and/or column if necessary
        if (r0 == true) {
            
            for (int i = 0; i < row; ++i) {
                
                matrix[i][0] = 0;
            }
        }
        
        if (c0 == true) {
            
            for (int j = 0; j < col; ++j) {
                
                matrix[0][j] = 0;
            }
        }
        
        
        return;
    }
};