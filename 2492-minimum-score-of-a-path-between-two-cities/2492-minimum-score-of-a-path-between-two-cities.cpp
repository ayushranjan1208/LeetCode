class Solution {
public:
    int dfs(int node, int par, vector<int> &vis, vector<vector<pair<int,int>>> &adj){
        vis[node] = 1;
        int mini = INT_MAX;

        for(auto [child,w] : adj[node]){
            if(vis[child]){
                if(child == par) continue;
                mini = min(mini,w);
            }
            else{
                mini = min(mini,w);
                mini = min(mini,dfs(child,node,vis,adj));
            }
        }
        return mini;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> vis(n + 1,0);

        return dfs(1,0,vis,adj);
    }
};