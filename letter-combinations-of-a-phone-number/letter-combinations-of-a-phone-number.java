class Solution {
    public List<String> letterCombinations(String digits) {
        
        LinkedList<String> combinations = new LinkedList<>();
        
        if (digits.isEmpty()) { return combinations; }
        
        String[] digitChars = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        String currentDigits, nextDigits;
        
        combinations.add("");
        
        while (combinations.peek().length() != digits.length()) {
            
            currentDigits = combinations.remove();
            
            nextDigits = digitChars[digits.charAt(currentDigits.length()) - '0' - 2];
            
            for (char ch : nextDigits.toCharArray()) {
                
                combinations.addLast(currentDigits + ch);
            }
        }
        
        return combinations;
    }
}

/*
    2 - abc
    3 - def
    4 - ghi
    5 - jkl
    6 - mno
    7 - pqrs
    8 - tuv
    9 - wxyz

*/