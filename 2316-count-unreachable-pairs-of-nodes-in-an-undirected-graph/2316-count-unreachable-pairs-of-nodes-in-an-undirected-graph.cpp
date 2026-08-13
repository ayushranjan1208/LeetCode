class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;

        int cnt = 0;
        for(auto &ch : adj[node]){
            if(vis[ch]) continue;
            cnt += dfs(ch,adj,vis);
        }

        return cnt + 1;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> grp, vis(n, 0);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int cnt = dfs(i,adj,vis);
                grp.push_back(cnt);
            }
        }

        long long tot = n;
        long long pairs = 0;
        for(auto g : grp){
            tot -= g;
            pairs += tot * 1ll * g;
        }

        return pairs;
    }
};