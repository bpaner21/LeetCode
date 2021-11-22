class Solution {
    public String findDifferentBinaryString(String[] nums) {
        
        int n = nums.length;
        
        StringBuilder unique = new StringBuilder();
        
        for (int i = 0; i < n; ++i) {
            
            char ch = nums[i].charAt(i) == '0' ? '1' : '0';
            
            unique.append(ch);
        }
        
        return unique.toString();
    }
}