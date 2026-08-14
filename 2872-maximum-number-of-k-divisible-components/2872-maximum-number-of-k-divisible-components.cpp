class Solution {
public:
    int cnt = 0;
    long long dfs(int node, int par, vector<vector<int>> &adj, vector<int>& values, int k){
        long long sum = 0;
        for(auto &ch : adj[node]){
            if(ch == par) continue;

            sum += dfs(ch,node,adj,values,k);
        }
        sum += values[node];
        if(sum % k == 0){
            cnt++;
            sum = 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,-1,adj,values,k);

        return cnt;
    }
};