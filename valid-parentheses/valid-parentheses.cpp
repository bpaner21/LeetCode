class Solution {
public:
    bool isValid(string s) {
        
        // An odd-lengthed string cannot have
        // a valid set of bracket pairs
        if (s.length() % 2 == 1) { return false;}
        
        stack<char> chStack;
        
        for (char c : s) {
            
            switch(c) {
                    
                case '(':
                    chStack.push(')');
                    break;
                    
                case '{':
                    chStack.push('}');
                    break;
                    
                case '[':
                    chStack.push(']');
                    break;
                    
                default:
                    if (chStack.empty() || c != chStack.top()) {
                        
                        return false;
                    }
                        
                    chStack.pop();
                    
                    
                    break;
            }
        }
        
        return chStack.empty();
    }
};