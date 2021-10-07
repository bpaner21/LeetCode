class Solution {
    public int islandPerimeter(int[][] grid) {
        
        int islands = 0, neighbors = 0;
        
        for (int row = 0; row < grid.length; ++row) {
            for (int col = 0; col < grid[0].length; ++col) {
                
                if (grid[row][col] == 1) {
                    
                    ++islands;
                    
                    if (row != 0 && grid[row - 1][col] == 1) { ++neighbors; }
                    if (col != 0 && grid[row][col - 1] == 1) { ++neighbors; }
                }
            }
        }
        
        return (islands * 4) - (neighbors * 2);
    }
}