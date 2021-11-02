class Solution {
    public boolean isValid(String s) {
        
        // an odd-length string cannot have
        // a valid set of bracket pairs
        if (s.length() % 2 == 1) { return false; }
        
        Stack<Character> chStack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            
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
                    if (chStack.isEmpty() || c != chStack.pop()) { return false; }
                    break;
            }
        }
        
        return chStack.isEmpty();
    }
}