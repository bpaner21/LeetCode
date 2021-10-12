class Solution {
    public int bulbSwitch(int n) {
        
        return (int) Math.sqrt(n);
    }
}

/*

    This is not a coding problem so much as it is a logic puzzle.
    
    Every bulb is initially off, but gets turned on so long as n >= 1,
    
    The bulbs that would be still be on after n rounds are those that have only an odd amount of factors,
    
    in otherwords, numbers that are perfect squares, between 0 and n, which can be easily calculated by the square root of n.
    
    * If n == 0, 0 is returned
    
    * If n == 1, 1 is returned since its only factor is itself
    
    * If n > 1, return the value of sqrt(n), rounding down to the nearest integer
*/