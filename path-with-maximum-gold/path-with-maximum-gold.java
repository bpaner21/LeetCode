class Solution {
    public int getMaximumGold(int[][] grid) {
        
        int gold = 0;
        
        for (int row = 0; row < grid.length; ++row) {
            for (int col = 0; col < grid[0].length; ++col) {
                
                gold = Math.max(gold, maxGold(grid, row, col));
            }
        }
        
        return gold;
    }
    
    private int maxGold(int[][] grid, int row, int col) {
        
        if (row < 0 || col < 0 || grid.length <= row || grid[0].length <= col || grid[row][col] <= 0) { return 0; }
        
        int gold = 0;
        
        grid[row][col] *= -1;
        
        gold = Math.max(gold, maxGold(grid, row - 1, col)); // left
        gold = Math.max(gold, maxGold(grid, row + 1, col)); // right
        gold = Math.max(gold, maxGold(grid, row, col - 1)); // up
        gold = Math.max(gold, maxGold(grid, row, col + 1)); // down
        
        grid[row][col] *= -1;
        
        return grid[row][col] + gold;
    }
}