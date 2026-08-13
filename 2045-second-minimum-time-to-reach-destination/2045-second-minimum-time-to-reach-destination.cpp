class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> d1(n + 1, INT_MAX), d2(n + 1, INT_MAX);

        queue<pair<int,int>> q;
        q.push({1,0});
        d1[1] = 0;

        while(!q.empty()){
            auto [u,d] = q.front();
            q.pop();

            for(auto &v : adj[u]){
                int nd = d + 1;
                if (nd < d1[v]) {
                    d1[v] = nd;
                    q.push({v, nd});
                }
                else if (nd > d1[v] && nd < d2[v]) {
                    d2[v] = nd;
                    q.push({v, nd});
                }
            }
        }

        int steps = d2[n];
        int ans = 0;
        for(int i = 1; i <= steps; i++){
            ans += time;
            int x = ans / change;
            if(x % 2 && i != steps){
                ans = change * (x + 1);
            }
        }

        return ans;

    }
};