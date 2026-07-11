class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefix(n+1,0);
        vector<int> plate_pos(n,-1);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i];
            if(i > 0) plate_pos[i] = plate_pos[i - 1];
            if(s[i] == '*'){
                prefix[i + 1]++;
            }
            else{
                plate_pos[i] = i;
            }
        }
        int q = queries.size();

        vector<int> ans(q);

        for(int i = 0; i < q; i++){
            int l = queries[i][0], r = queries[i][1];

            int ind = lower_bound(plate_pos.begin(),plate_pos.end(),l) - plate_pos.begin();

            if(ind == n){
                ans[i] = 0;
                continue;
            }

            int st = plate_pos[ind], en = plate_pos[r];

            if(st >= en){
                ans[i] = 0;
                continue;
            }

            ans[i] = prefix[en + 1] - prefix[st];
        }
        return ans;

    }
};