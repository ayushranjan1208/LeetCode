class Solution {
public:
    vector<int> vis;
    int ans = -1;

    void dfs(int node, int num, vector<vector<int>> &adj){
        vis[node] = num;
        for(int &ch : adj[node]){
            if(vis[ch] == -1) continue;

            if(vis[ch] != 0){
                ans = max(ans, num - vis[ch] + 1);
                continue;
            }
            dfs(ch, num + 1, adj);
        }

        vis[node] = -1;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }

        vis.assign(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,1,adj);
            }
        }

        return ans;
    }
};