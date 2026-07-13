class Solution {
public:
    void fun(vector<vector<int>> &ans, vector<int> &v, vector<int> &nums, int ind){
        ans.push_back(v);
        
        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;

            v.push_back(nums[i]);
            fun(ans,v,nums,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        fun(ans,v,nums,0);
        return ans;
    }
};