class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pQ(piles.begin(), piles.end());
        
        for (int i = 0; i < k; ++i) {
            
            int temp = pQ.top();
            pQ.pop();
            pQ.push(temp - (temp / 2));
        }
        
        int min = 0;
        
        while (!pQ.empty()) {
            
            min += pQ.top();
            pQ.pop();
        }
        
        return min;
    }
};