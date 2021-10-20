class Solution {
public:
    int reverse(int x) {
        
        if (x < INT_MIN || x > INT_MAX) { return 0; }
        
        long int reverseInt = 0;
        
        int newDigit, temp;
        
        while (x != 0) {
            
            newDigit = x % 10;
            
            temp = (reverseInt * 10) + newDigit;
            
            if ((temp - newDigit) / 10 != reverseInt) { return 0; }
            
            reverseInt = temp;
            
            x /= 10;
        }
        
        return (int)reverseInt;
    }
};