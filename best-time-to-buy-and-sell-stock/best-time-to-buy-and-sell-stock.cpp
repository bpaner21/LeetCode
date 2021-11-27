class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buyLow = INT_MAX, sellHigh = 0;
        
        for (int p : prices) {
            
            buyLow = min(buyLow, p);
            
            sellHigh = max(sellHigh, p - buyLow);
            
            //cout << "low: " << buyLow << ", high: " << sellHigh << endl;
        }
        
        return sellHigh;
    }
};