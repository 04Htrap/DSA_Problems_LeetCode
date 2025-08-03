class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> inDegree(n);
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++) {
            for(auto node : graph[i]){
                adj[node].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while(!q.empty()){
            int node = q.front();
            safe[node] = true;
            q.pop();

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(safe[i])
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};