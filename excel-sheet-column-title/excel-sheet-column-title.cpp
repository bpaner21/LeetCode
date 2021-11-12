class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        std::string title = "";
        
        while (columnNumber != 0) {
            
            columnNumber -= 1;
            
            char ch = 'A' + (columnNumber % 26);
            
            title.insert(title.begin(), ch);
            
            columnNumber /= 26;
        }
            
        return title;
    }
};