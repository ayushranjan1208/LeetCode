class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, set<int> &s){
        vis[node] = 1;
        s.insert(node);

        for(auto &ch : adj[node]){
            if(vis[ch]) continue;
            dfs(ch,adj,vis,s);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_map<int,set<int>> mp;
        vector<int> par(c + 1), on(c + 1, 1); 
        vector<int> vis(c + 1, 0);
        for(int i = 1; i <= c; i++){
            if(!vis[i]){
                set<int> s;
                dfs(i,adj,vis,s);
                for(auto it : s){
                    par[it] = i;
                }
                mp[i] = s;
            }
        }

        vector<int> ans;
        for(auto &q : queries){
            int t = q[0], n = q[1];
            if(t == 1){
                int x;
                if(on[n]){
                    x = n;
                }
                else{
                    int p = par[n];
                    if(mp[p].size() == 0) x = -1;
                    else{
                        x = *(mp[p].begin());
                    }
                }
                ans.push_back(x);
            }
            else{
                on[n] = 0;
                int p = par[n];
                auto it = mp[p].find(n);
                if(it != mp[p].end()){
                    mp[p].erase(it);
                }
            }
        }

        return ans;

    }
};