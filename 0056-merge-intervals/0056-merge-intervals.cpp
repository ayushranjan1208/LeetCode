class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int l = intervals[0][0], r = intervals[0][1];
        for(int i = 1; i < n; i++){
            int nl = intervals[i][0], nr = intervals[i][1];
            if(nl <= r) r = max(r,nr);
            else{
                ans.push_back({l,r});
                l = nl, r = nr;
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};