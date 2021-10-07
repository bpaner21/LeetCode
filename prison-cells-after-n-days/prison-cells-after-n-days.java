class Solution {
    public int[] prisonAfterNDays(int[] cells, int n) {
        
        // Because this problem can go up to 10^9 days
        // rather than calculating the state of each day manually,
        // it is much more time efficient to attempt to find a cycle
        // between the states of cells 1 through cells.size() - 2
        //
        // This is because any given state can only become one other state the next day
        // and there are only 14 permutations for the states of cells 1 through cells.size() - 2
        //
        // Due to the rules, cells[0] and cells[cells.size() - 1] will always become 0 by the second day,
        // thus they can be ignored when trying to find a cycle between states

        int[] temp = new int[8];
        
        // Find the number of states to loop through by 
        // calculating how many times the cells would cycle through states 1 - 14
        // and find the remaining number of days left
        //
        // because the value of both the first and last cells may begin at 1, the loop will cycle between 1 - 14 times
        // to ensure that they are they are properly set to 0
        
        for (n = ((n - 1) % 14) + 1; n > 0; --n) {
            
            for (int i = 1; i < 7; ++i) {
                
                temp[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
            }
            
            cells = temp.clone();
        }
        
        return cells;
    }
}