class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int gold = 0;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                
                gold = max(gold, maxGold(grid, row, col));
            }
        }
        
        return gold;
    }
    
private:
    
    int maxGold(vector<vector<int>>& grid, int row, int col) {
        
        if (row < 0 || col < 0 || grid.size() <= row || grid[0].size() <= col || grid[row][col] <= 0) { return 0; }
        
        int gold = 0;
        
        grid[row][col] *= -1;
        
        gold = max(gold, maxGold(grid, row - 1, col));
        gold = max(gold, maxGold(grid, row + 1, col));
        gold = max(gold, maxGold(grid, row, col - 1));
        gold = max(gold, maxGold(grid, row, col + 1));
        
        grid[row][col] *= -1;
        
        return grid[row][col] + gold;
    }
};