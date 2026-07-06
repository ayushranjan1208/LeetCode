class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),cmp);

        int l = intervals[0][0], r = intervals[0][1];
        int c = 1;

        for(int i = 0; i < n; i++){
            int nl = intervals[i][0], nr = intervals[i][1];
            if(nr > r){
                c++;
                l = nl, r = nr;
            }
        }
        return c;
    }
};