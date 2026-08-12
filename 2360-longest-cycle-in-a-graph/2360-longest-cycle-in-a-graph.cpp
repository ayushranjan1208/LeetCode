class Solution {
public:
    vector<int> vis;
    int ans = -1;

    void dfs(int node, int num, vector<int> &edges){
        if(node == -1) return;

        vis[node] = num;
        int ch = edges[node];
        if(ch != -1 && vis[ch] == 0){
            dfs(ch, num + 1, edges);
        }
        else{
            if(ch != -1 && vis[ch] != -1){
                ans = max(ans, num - vis[ch] + 1);
            }
        }
        vis[node] = -1;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vis.assign(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i,1,edges);
            }
        }

        return ans;
    }
};