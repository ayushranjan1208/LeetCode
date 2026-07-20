class Solution {
public:
    void reverse(vector<vector<int>> &grid, int l, int r, int m){
        while(l < r){
            swap(grid[l/m][l%m], grid[r/m][r%m]);
            l++;
            r--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int t = n * m;

        k = k % t;

        reverse(grid,0,t-1,m);
        reverse(grid,0,k-1,m);
        reverse(grid,k,t-1,m);

        return grid;
    }
};