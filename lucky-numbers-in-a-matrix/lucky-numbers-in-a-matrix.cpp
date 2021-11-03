class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size(),
            minRow = INT_MIN, maxCol = INT_MAX;
        
        vector<int> lucky {};
        
        
        // find the largest row-minimum value
        for (int row = 0; row < m; ++row) {
            
            int currentMin = INT_MAX;
            
            for (int col = 0; col < n; ++col) {
                
                currentMin = min(currentMin, matrix[row][col]);
            }
            
            minRow = max(minRow, currentMin);
        }
        
        
        // find the smallest column-maximum value
        for (int col = 0; col < n; ++col) {
            
            int currentMax = INT_MIN;
            
            for (int row = 0; row < m; ++row) {
                
                currentMax = max(currentMax, matrix[row][col]);
            }
            
            maxCol = min(maxCol, currentMax);
        }
        
        
        if (minRow == maxCol) { lucky.push_back(minRow); }
        
        return lucky;
    }
};