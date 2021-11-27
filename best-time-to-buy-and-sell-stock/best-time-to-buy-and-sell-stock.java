class Solution {
    public int maxProfit(int[] prices) {
        
        int buyLow = Integer.MAX_VALUE, sellHigh = 0;
        
        for (int p : prices) {
            
            buyLow = Math.min(buyLow, p);
            
            sellHigh = Math.max(sellHigh, p - buyLow);
            
            //System.out.println("low: " + buyLow + ", high: " + sellHigh);
        }
        
        return sellHigh;
    }
}