class Solution {
    public String interpret(String command) {
        
        StringBuilder goal = new StringBuilder();
        
        int i = 0;
        
        while (i < command.length()) {
            
            if (command.charAt(i++) == '(') {
                
                if (command.charAt(i++) == ')') {
                    
                    goal.append('o');
                }
                else {
                    
                    goal.append("al");
                    
                    i += 2;
                }
            }
            else {
                
                goal.append('G');
            }
        }
        
        return goal.toString();
    }
}