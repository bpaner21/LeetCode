class Solution {
public:
    
    vector<string> letterCombinations(const string& digits) {
        
        if (digits.empty()) return {};
        
        vector<string> temp = {}, combinations = {""}, digitChars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currentDigit;
        
        for (int i = 0; i < digits.size(); ++i) {
            
            temp.clear();
            
            currentDigit = digitChars[ (digits[i] - '0' - 2) ];
            
            for (int j = 0; j < combinations.size(); ++j) {
                
                for (int k = 0; k < currentDigit.size(); ++k) {
                    
                    //cout << combinations[j] << currentDigit[k] << endl;
                    
                    temp.push_back (combinations[j] + currentDigit[k]);
                }
            }
            
            combinations.swap(temp);
        } 
        
        return combinations;
    }
};

/*

    2 - abc
    3 - def
    4 - ghi
    5 - jkl
    6 - mno
    7 - pqrs
    8 - tuv
    9 - wxyz

    vector<vector<char>> letters

*/