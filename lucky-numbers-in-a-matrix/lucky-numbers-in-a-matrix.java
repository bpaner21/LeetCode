class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        
        int m = matrix.length, n = matrix[0].length,
            minRow = Integer.MIN_VALUE, maxCol = Integer.MAX_VALUE;
        
        ArrayList<Integer> lucky = new ArrayList<>();
        
        
        for (int row = 0; row < m; ++row) {
            
            int currentMin = Integer.MAX_VALUE;
            
            for (int col = 0; col < n; ++col) {
                
                currentMin = Math.min(currentMin, matrix[row][col]);
            }
            
            minRow = Math.max(minRow, currentMin);
        }
        
        
        for (int col = 0; col < n; ++col) {
            
            int currentMax = Integer.MIN_VALUE;
            
            for (int row = 0; row < m; ++row) {
                
                currentMax = Math.max(currentMax, matrix[row][col]);
            }
            
            maxCol = Math.min(maxCol, currentMax);
        }
        
        
        if (minRow == maxCol) { lucky.add(minRow); }
        
        return lucky;
    }
}