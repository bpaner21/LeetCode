class Solution {
public:
    string interpret(string command) {
        
        std::string goal = "";
        
        int i = 0;
        
        while (i < command.size()) {
            
            if (command[i++] == '(') {
                
                if (command[i++] == ')') {
                    
                    goal += 'o';
                }
                else {
                    
                    goal += "al";
                    
                    i += 2;
                }
            }
            else {
                
                goal += "G";
            }
        }
        
        return goal;
    }
};