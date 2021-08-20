class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int[] sum = {0, 0};
        
        HashMap<Integer, Integer> hMap = new HashMap<>();
        
        for (int i = 0; i < nums.length; ++i) {
            
            int difference = target - nums[i];
            
            if (hMap.containsKey(difference)) {
                
                sum[0] = hMap.get(difference);
                sum[1] = i;
                
                return sum;
            }
            
            hMap.put(nums[i], i);
        } 
        
        return sum;
    }
}