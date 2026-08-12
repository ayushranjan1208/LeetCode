class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    vector<vector<int>> dp;
    int ans = 0;

    void dfs(int node, string &col){
        vis[node] = 1;
    
        for(auto &child : adj[node]){
            if(vis[child] == 1){
                ans = INT_MAX;
                return;
            }
            if(vis[child] == 0) dfs(child,col);
            if(ans == INT_MAX) return;

            for(int i = 0; i < 26; i++){
                dp[node][i] = max(dp[node][i], dp[child][i]);
            }
        }

        dp[node][col[node] - 'a']++;

        for(int i = 0; i < 26; i++) ans = max(ans, dp[node][i]);

        vis[node] = 2;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        adj.assign(n, vector<int>());
        dp.assign(n,vector<int>(26,0));

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
        }

        vis.assign(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,colors);
                if(ans == INT_MAX) return -1;
            }
        }

        return ans;
    }
};