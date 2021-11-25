class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> map {};
        priority_queue<int> q {};
        int minSet = 0, count = 0;
        
        // count occurrence of all integers in array
        for (int a : arr) {
            
            ++map[a];
        }
        
        // push occurence into priority queue
        for (auto m : map) {
            
            q.push(m.second);
        }
        
        // greedily remove integers until
        // array is at least half its original size
        while (count * 2 < arr.size()) {
            
            ++minSet;
            count += q.top();
            q.pop();
        }
        
        return minSet;
    }
};