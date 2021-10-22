class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pQ(piles.begin(), piles.end());
        
        int temp;
        
        for (int i = 0; i < k; ++i) {
            
            temp = pQ.top();
            pQ.pop();
            
            temp -= floor(temp / 2);
            pQ.push(temp);
        }
        
        int min = 0;
        
        while (!pQ.empty()) {
            
            min += pQ.top();
            pQ.pop();
        }
        
        return min;
    }
};