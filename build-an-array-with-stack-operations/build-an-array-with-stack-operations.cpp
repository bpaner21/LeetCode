class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<std::string> stack {};
        
        int currentNum = 1;
        
        for (int i = 0; i < target.size(); ++i) {
            
            while (currentNum != target[i]) {
                
                stack.push_back("Push");
                stack.push_back("Pop");
                ++currentNum;
            }
            
            stack.push_back("Push");
            ++currentNum;
        }
        
        return stack;
    }
};