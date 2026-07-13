class Solution {
public:
    void fun(vector<vector<int>> &ans, vector<int> &v, vector<int> &c, int ind, int target){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        if(ind == c.size()) return;

        for(int i = ind; i < c.size(); i++){
            if(i > ind && c[i] == c[i-1]) continue;

            if(target >= c[i]){
                v.push_back(c[i]);
                fun(ans,v,c,i+1,target - c[i]);
                v.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        fun(ans,v,candidates,0,target);
        return ans;
    }
};