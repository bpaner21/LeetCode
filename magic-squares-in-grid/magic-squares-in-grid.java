class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        
        if (grid.length < 3 || grid[0].length < 3) { return 0; }
        
        int mSCount = 0;
        
        for (int row = 0; row <= grid.length - 3; ++row) {
            for (int col = 0; col <= grid[0].length - 3; ++col) {
                
                if (isMagicSquare(grid, row, col)) { ++mSCount; }
            }
        }
        
        return mSCount;
    }
    
    private boolean isMagicSquare(int[][] grid, int row, int col) {
        
        // is the center of the current 3x3 grid 5
        if (grid[row + 1][col + 1] != 5) { return false; } 
        
        // are the corners even
        if (grid[row][col] % 2 != 0) { return false; }          // top left
        if (grid[row][col + 2] % 2 != 0) { return false; }      // top right
        if (grid[row + 2][col] % 2 != 0) { return false; }      // bottom left
        if (grid[row + 2][col + 2] % 2 != 0) { return false; }  // bottom right
            
        // are the sides odd
        if (grid[row][col+1] % 2 != 1) { return false; }        // top center
        if (grid[row+1][col] % 2 != 1) { return false; }        // center left
        if (grid[row+1][col+2] % 2 != 1) { return false; }      // center right
        // bottom center is unnecessary if the last 7 checks passed
        
        // do the the rows and columns around the center add up to 15
        if (grid[row][col] + grid[row + 1][col] + grid[row + 2][col] != 15) { return false; }   // left column
        if (grid[row][col] + grid[row][col + 1] + grid[row][col + 2] != 15) { return false; }   // top row
        if (grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2] != 15) { return false; }   // right column
        // bottom row is unnecessary if the last 3 checks passed
        
        
        return true;
    } 
}

/*

Magic squares using only the digits 1 - 9 are all rotations of a distinct arrangement:

8	1	6
3	5	7
4	9	2

There are a few rules that can be observed from this:

- 5 is always in the center of the grid

- Every row, column, and diagonal add up to 15

- Following the previous two rules, digits on opposite corners and sides add up to 10

- Every corner is an even digit, and every side is odd

*/