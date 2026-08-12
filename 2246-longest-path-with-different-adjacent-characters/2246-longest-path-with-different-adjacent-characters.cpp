class Solution {
public:
    vector<int> depth;
    int ans = 0;

    void dfs(int node, vector<vector<int>> &adj, string &s){
        int max1 = 0, max2 = 0;
        for(int &ch : adj[node]){
            if(s[node] == s[ch]) dfs(ch,adj,s);
            else{
                dfs(ch,adj,s);
                depth[node] = max(depth[node], depth[ch]);
                if(depth[ch] > max1){
                    max2 = max1;
                    max1 = depth[ch];
                }
                else if(depth[ch] > max2) max2 = depth[ch];
            }
        }
        depth[node]++;

        ans = max(ans, 1 + max1 + max2);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }

        depth.assign(n,0);

        dfs(0,adj,s);

        return ans;
    }
};