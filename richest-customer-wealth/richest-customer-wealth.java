class Solution {
    public int maximumWealth(int[][] accounts) {
        
        int maxWealth = Integer.MIN_VALUE;
        
        for (int[] a : accounts) {
            
            maxWealth = Math.max(maxWealth, Arrays.stream(a).sum());
        }
        
        return maxWealth;
    }
}