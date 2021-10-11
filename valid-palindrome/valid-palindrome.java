class Solution {
    public boolean isPalindrome(String s) {
        
        char[] sArr = s.toCharArray();
        
        int i = 0, j = sArr.length - 1;
        
        while (i < j) {
            
            while (i < j && !Character.isLetterOrDigit(sArr[i])) { ++i; }
            while (i < j && !Character.isLetterOrDigit(sArr[j])) { --j; }
            
            if (Character.toLowerCase(sArr[i]) != Character.toLowerCase(sArr[j])) { return false; }
            
            ++i;
            --j;
        }
        
        return true;
    }
}