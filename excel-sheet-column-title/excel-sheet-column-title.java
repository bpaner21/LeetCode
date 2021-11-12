class Solution {
    public String convertToTitle(int columnNumber) {
        
        StringBuilder title = new StringBuilder();
        
        while (columnNumber != 0) {
            
            columnNumber -= 1;
            
            char ch = (char)('A' + (columnNumber % 26));
            
            title.append(ch);
            
            columnNumber /= 26;
        }
        
        title.reverse();
            
        return title.toString();
    }
}