class Solution {
public:
    int reverse(const int& x) {
        
        if (x < INT_MIN || x > INT_MAX) { return 0; }
        
        long int reverseInt = 0;
        
        int x2 = x;
        
        while (x2) {
            
            int newDigit = x2 % 10;
            
            int temp = reverseInt * 10 + newDigit;
            
            if ((temp - newDigit)/ 10 != reverseInt) { return 0; }
            
            reverseInt = temp;
            
            x2 /= 10;
        }
        
        return reverseInt;
    }
};