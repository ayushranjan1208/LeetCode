class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, vector<int> &vis, int &cnt_nodes, int &cnt_edges){
        vis[node] = 1;
        cnt_nodes++;
        cnt_edges += adj[node].size();
        for(auto child : adj[node]){
            if(vis[child]) continue;
            dfs(adj,child,vis,cnt_nodes,cnt_edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                int cnt_nodes = 0, cnt_edges = 0;
                dfs(adj,i,vis,cnt_nodes,cnt_edges);
                if(cnt_edges == cnt_nodes * (cnt_nodes - 1)) cnt++;
            }
        }
        return cnt;
    }
};