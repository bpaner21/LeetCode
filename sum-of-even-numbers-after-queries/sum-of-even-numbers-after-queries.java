class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        
        int evenSums[] = new int[queries.length];
        
        int currentSum = 0;
        
        for (int n : nums) { if (n % 2 == 0) { currentSum += n; } }
        
        for (int i = 0; i < queries.length; ++i) {
            
            int j = queries[i][1];
            
            if (nums[j] % 2 == 0) { currentSum -= nums[j]; }
            
            nums[j] += queries[i][0];
            
            if (nums[j] % 2 == 0) { currentSum += nums[j]; }
            
            evenSums[i] = currentSum;
        }
        
        return evenSums;
    }
}