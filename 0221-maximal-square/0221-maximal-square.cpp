class Solution {
public:
    bool check(int k, vector<vector<int>> &pf){
        int n = pf.size(), m = pf[0].size();

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                int a = i, b = j, c = i + k - 1, d = j + k - 1;
                if(c >= n || d >= m) continue;
                int area = pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1];

                if(area == k * k) return true;
            }
        }

        return false;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> pf(n + 1, vector<int>(m + 1,0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                pf[i][j] = (matrix[i-1][j-1] == '1') + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
            }
        }

        int lo = 0, hi = min(n,m);
        int ans = 0;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(mid,pf)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans * ans;
    }
};