class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int lo = 0, hi = m - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            int maxi = -1,id = -1;
            for(int i = 0; i < n; i++){
                if(mat[i][mid] > maxi){
                    maxi = mat[i][mid];
                    id = i;
                }
            }

            int pre = (mid == 0) ? -1 : mat[id][mid - 1];
            int nxt = (mid == m - 1) ? -1 : mat[id][mid + 1];

            if(maxi > pre && maxi > nxt) return {id,mid};

            if(pre > maxi) hi = mid - 1;
            else lo = mid + 1;
        }
        return {-1,-1};
    }
};