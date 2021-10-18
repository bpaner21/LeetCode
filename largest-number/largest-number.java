class Solution {
    public String largestNumber(int[] nums) {
        
        if (nums == null || nums.length == 0) { return ""; }
        if (nums.length == 1) { return String.valueOf(nums[0]); }
        
        String[] sN = new String[nums.length];
        
        for (int i = 0; i < nums.length; ++i) {
            
            sN[i] = String.valueOf(nums[i]);
        }
        
        Arrays.sort(sN, (i, j) -> (j + i).compareTo(i + j));
        
        // if 0 is the only value in the array, return "0"
        if (sN[0].charAt(0) == '0') { return "0"; }
        
        StringBuilder sB = new StringBuilder();
        
        for (String s : sN) {
            
            sB.append(s);
        }
        
        return sB.toString();
    }
}