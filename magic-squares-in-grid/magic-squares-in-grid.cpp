class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        if (grid.size() < 3 || grid[0].size() < 3) { return 0; }
        
        int mSCount = 0;
        
        for (int row = 0; row <= grid.size() - 3; ++row) {
            for (int col = 0; col <= grid[0].size() - 3; ++col) {
                
                if (isMagicSquare(grid, row, col)) { ++mSCount; }
            }
        }
        
        return mSCount;
    }
    
private:
    bool isMagicSquare(const vector<vector<int>>& grid, const int& row, const int& col) {
        
        // is the center of the current 3x3 grid 5
        if (grid[row + 1][col + 1] != 5) { return false; } 
        
        /*  a   b   c
            d   e   f
            g   h   i
        */
        
        int a = grid[row][col], 
            b = grid[row][col + 1], 
            c = grid[row][col + 2], 
            d = grid[row + 1][col],
            f = grid[row + 1][col + 2], 
            g = grid[row + 2][col], 
            h = grid[row + 2][col + 2], 
            i = grid[row + 2][col + 2];
        
        // are the corners even
        if (a % 2 != 0) { return false; }   // top left
        if (c % 2 != 0) { return false; }   // top right
        if (g % 2 != 0) { return false; }   // bottom left
        if (i % 2 != 0) { return false; }   // bottom right
            
        // are the sides odd
        if (b % 2 != 1) { return false; }   // top center
        if (d % 2 != 1) { return false; }   // center left
        if (f % 2 != 1) { return false; }   // center right
        // bottom center is unnecessary if the last 7 checks passed
        
        // do the the rows and columns around the center add up to 15
        if (a + d + g != 15) { return false; }   // left column
        if (a + b + c != 15) { return false; }   // top row
        if (c + f + i != 15) { return false; }   // right column
        // bottom row is unnecessary if the last 3 checks passed
        
        return true;
    }

};

/*

a   b   c
d   e   f
g   h   i

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