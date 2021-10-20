class Solution {
    public int reverse(int x) {
        
        int reverse = 0;
        
        while (x != 0) {
            
            int newDigit = x % 10;
            
            int temp = (reverse * 10) + newDigit;
            
            if ((temp - newDigit) / 10 != reverse) { return 0; }
            
            reverse = temp;
                
            x /= 10;
        }
        
        return reverse;
    }
}