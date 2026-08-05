class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;

        for(auto child : adj[node]){
            if(vis[child]) continue;
            dfs(child,vis,adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i = 0; i < invocations.size(); i++){
            int u = invocations[i][0], v = invocations[i][1];
            adj[u].push_back(v);
        }

        dfs(k,vis,adj);

        bool flag = false;

        for(int i = 0; i < invocations.size(); i++){
            int u = invocations[i][0], v = invocations[i][1];
            if(vis[v] == 1 && vis[u] == 0) flag = true;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0 || flag) ans.push_back(i);
        }

        return ans;
    }
};