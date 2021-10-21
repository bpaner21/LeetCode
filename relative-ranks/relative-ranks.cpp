class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string> rank(score.size(), "");
        
        priority_queue<pair<int, int>> pQ;
        
        for (int i = 0; i < score.size(); ++i) {
            
            pQ.push(make_pair(score[i],i));
        }
        
        for (int j = 0; j < rank.size(); ++j) {
            
            pair<int,int> r = pQ.top();
            pQ.pop();
            
            rank[r.second] = to_string(j + 1);
            
            if (j == 0) { rank[r.second] = "Gold Medal"; }
            if (j == 1) { rank[r.second] = "Silver Medal"; }
            if (j == 2) { rank[r.second] = "Bronze Medal"; }
            
        }
        
        return rank;
    }
};