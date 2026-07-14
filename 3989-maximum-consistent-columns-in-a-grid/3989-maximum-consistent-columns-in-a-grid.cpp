class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(n,1);
        int ans = 0;
        for(int i = 0; i < n; i++){

            int cur = 1;
            for(int j = 0; j < i; j++){

                bool t = true;
                for(int k = 0; k < m; k++){

                    if(abs(grid[k][i] - grid[k][j]) > limit){
                        t = false;break;
                    }

                }
                if(t){
                    cur = max(cur,dp[j] + 1);
                }
            }
            ans = max(ans,cur);
            dp[i] = cur;
        }

        return ans;

    }
};