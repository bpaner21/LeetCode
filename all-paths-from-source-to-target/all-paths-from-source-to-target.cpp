class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> fullPath {};
     
        vector<int> currentPath {};
        
        DFS(0, graph, fullPath, currentPath);
        
        return fullPath;
    }
    
private:
    void DFS(int i, vector<vector<int>>& graph, vector<vector<int>>& fullPath, vector<int> currentPath) {
        
        currentPath.push_back(i);
        
        if (i == graph.size() - 1) {
            
            fullPath.push_back(currentPath);
            
        } else {
            
            for (int g : graph[i]) {
                
                DFS(g, graph, fullPath, currentPath);
            }
            
        }
        
        currentPath.pop_back();
        
        return;
    }
};